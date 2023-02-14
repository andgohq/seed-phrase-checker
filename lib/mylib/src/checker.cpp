#include <string>
#include <vector>

#include <sha2.h>

#include <checker.hpp>
#include <utility>
#include <wordlist.hpp>

std::vector<std::string> split(const std::string &str) {
  std::vector<std::string> elems;
  std::string item;
  for (char ch : str) {
    if (ch == ' ') {
      if (!item.empty())
        elems.push_back(item);
      item.clear();
    } else {
      item += ch;
    }
  }
  if (!item.empty())
    elems.push_back(item);
  return std::move(elems);
}

CheckResult checkSeedPhrase(const std::string &str) {
  CheckResult result = {SUCCESS, 0};

  auto words = split(str);
  std::vector<int> indexList;

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
      result.errorCode = FAIL_WORD;
    } else {
      result.wordsNotInList[i] = false;
      indexList.push_back(idx);
    }
  }

  if (result.errorCode == FAIL_WORD) {
    return result;
  }

  uint8_t bytes[33];
  uint8_t hash[32];
  packToBytes(indexList, bytes, 33);
  sha256_Raw(bytes, 32, hash);

  if (hash[0] == bytes[32]) {
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