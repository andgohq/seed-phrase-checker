#include <string>
#include <vector>

#include <sha2.h>

#include <checker.hpp>
#include <utility>
#include <wordlist.hpp>

// only for unit test
CheckResult checkSeedPhrase(const std::string &text) {
  std::vector<std::string> words;
  std::string item;
  for (char ch : text) {
    if (ch == ' ') {
      if (!item.empty())
        words.push_back(item);
      item.clear();
    } else {
      item += ch;
    }
  }
  if (!item.empty())
    words.push_back(item);
  return checkSeedPhrase(words);
}

CheckResult checkSeedPhrase(const std::vector<std::string> &words) {
  CheckResult result = {0};

  std::vector<int> indexList;

  auto wordNum = words.size();

  if (wordNum == 0) {
    result.errorCode = FAIL_EMPTY;
    return result;
  }

  // Check if each word is in wordlist
  int i = 0;
  for (auto &word : words) {
    int idx = 0;

    for (auto &w : wordlist) {
      if (word.compare(w) == 0) {
        break;
      }
      idx++;
    }
    if (idx == 2048) {
      result.wordsNotInList[i] = true;
      result.count++;
      result.errorCode = FAIL_WORD;
    } else {
      result.wordsNotInList[i] = false;
      indexList.push_back(idx);
    }
    i++;
  }

  if (result.errorCode == FAIL_WORD) {
    return result;
  }

  // Check word number
  if (!(wordNum == 12 || wordNum == 15 || wordNum == 18 || wordNum == 21 ||
        wordNum == 24)) {
    result.errorCode = FAIL_WORD_NUMBER;
    return result;
  }

  // Check hash
  uint8_t bytes[33];
  uint8_t hash[32];

  auto entoropyBytes = wordNum * 11 / 33 * 4;
  auto checksumBits = wordNum * 11 / 33;

  packToBytes(indexList, bytes, 33);
  sha256_Raw(bytes, entoropyBytes, hash);

  if ((bytes[entoropyBytes] >> (8 - checksumBits)) ==
      hash[0] >> (8 - checksumBits)) {
    return result;
  } else {
    result.errorCode = FAIL_CHECK_SUM;
    return result;
  }
}

bool checkLastWord(std::string str) {
  char wordFound = false;
  int idx = str.length() - 1;
  int end = idx;

  for (auto it = str.rbegin(), e = str.rend(); it != e; ++it, --idx) {
    if (*it != ' ' && wordFound == false) {
      wordFound = true;
      end = idx;
    } else if (*it == ' ' && wordFound == true) {
      break;
    }
  }
  std::string lastWord = str.substr(idx + 1, end - idx);

  for (auto &word : wordlist) {
    if (lastWord.compare(word) == 0) {
      return true;
    }
  }
  return false;
}

void packToBytes(std::vector<int> indexList, uint8_t *bytes, size_t size) {
  int i = 0;  // byte index
  int s = 11; // index remained
  int p = 8;  // byte remained
  bytes[i] = 0;

  for (auto idx : indexList) {
    s = 11;
    while (s > 0) { // bytes loop
      if (s >= p) {
        bytes[i] |= ((0xff >> (8 - p)) & (idx >> (s - p)));
        s -= p;
        p = 8;
        i++;
        if (i >= size) {
          return;
        }
        bytes[i] = 0;
      } else {
        bytes[i] |= ((0xff >> (8 - s)) & idx) << (p - s);
        p -= s;
        break;
      }
    }
  }
}