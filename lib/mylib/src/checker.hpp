#include <string>

typedef struct CheckResult {
  int errorCode;
  bool wordsNotInList[24];
} CheckResult;

CheckResult checkSeedPhrase(const std::string &str);
bool checkLastWord(std::string str);
void packToBytes(std::vector<int> indexList, uint8_t *bytes, size_t size);

#define SUCCESS 0
#define FAIL_CHECK_SUM 1
#define FAIL_WORD 2