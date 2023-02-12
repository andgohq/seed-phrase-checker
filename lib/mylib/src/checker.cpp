#include <algorithm>
#include <string>
#include <wordlist.hpp>

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