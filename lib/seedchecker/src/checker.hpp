#include <string>

typedef struct CheckResult {
  int errorCode;
  bool wordsNotInList[24];
  int count;
} CheckResult;

CheckResult checkSeedPhrase(const std::string &text);
CheckResult checkSeedPhrase(const std::vector<std::string> &words);
bool checkLastWord(std::string str);
void packToBytes(std::vector<int> indexList, uint8_t *bytes, size_t size);

#define SUCCESS 0
#define FAIL_EMPTY 1
#define FAIL_WORD 2
#define FAIL_WORD_NUMBER 3
#define FAIL_CHECK_SUM 4
