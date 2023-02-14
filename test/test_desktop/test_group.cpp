#include <iostream>
#include <string>
#include <vector>

#include "unity_fixture.h"
#include <unity.h>

#include <checker.hpp>

TEST_SETUP(checker) {}

TEST_TEAR_DOWN(checker) {}

void test_checkLastWord() {
  TEST_ASSERT_EQUAL(true, checkLastWord("act"));
  TEST_ASSERT_EQUAL(true, checkLastWord(" act"));
  TEST_ASSERT_EQUAL(true, checkLastWord("  act  "));
  TEST_ASSERT_EQUAL(true, checkLastWord(" aaa void  "));
  TEST_ASSERT_EQUAL(true, checkLastWord(" aaa void"));
  TEST_ASSERT_EQUAL(false, checkLastWord("actt"));
  TEST_ASSERT_EQUAL(false, checkLastWord(" actt"));
  TEST_ASSERT_EQUAL(false, checkLastWord(" actt "));
  TEST_ASSERT_EQUAL(false, checkLastWord(" act  actt "));
}

void test_checkSeedPhrase() {
  //
  TEST_ASSERT_EQUAL(
      SUCCESS, checkSeedPhrase(
                   " void come effort suffer camp survey warrior heavy shoot "
                   "primary clutch crush  open amazing screen patrol group "
                   "space point ten exist slush involve unfold ")
                   .errorCode);
  TEST_ASSERT_EQUAL(
      FAIL_CHECK_SUM,
      checkSeedPhrase("act come effort suffer camp survey warrior heavy shoot "
                      "primary clutch crush open amazing screen patrol group "
                      "space point ten exist slush involve unfold")
          .errorCode);
  TEST_ASSERT_EQUAL(
      FAIL_WORD,
      checkSeedPhrase("act come effort suffer camp survey warrior heavy shoot "
                      "primary clutch crush open amazing screen patrol group "
                      "space point ten exist slush involve unfolding")
          .errorCode);
}

void test_packToBytes() {
  uint8_t bytes[64];
  uint8_t bytesA[] = {154, 87,  77,  42, 243, 73,  165,
                      116, 210, 175, 52, 230, 156, 208};
  std::vector<int> indexList = {1234, 1491, 597,  1844, 1234,
                                1491, 597,  1844, 1844, 1844};
  packToBytes(indexList, bytes, 64);
  TEST_ASSERT_EQUAL_UINT8_ARRAY(bytesA, bytes, 13);
}

void test_runner(void) {
  RUN_TEST(test_checkLastWord);
  RUN_TEST(test_checkSeedPhrase);
  RUN_TEST(test_packToBytes);
}