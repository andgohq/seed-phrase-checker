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
  // valid 24 words
  TEST_ASSERT_EQUAL(
      SUCCESS, checkSeedPhrase(
                   " void come effort suffer camp survey warrior heavy shoot "
                   "primary clutch crush  open amazing screen patrol group "
                   "space point ten exist slush involve unfold ")
                   .errorCode);

  // invalid 24 words

  TEST_ASSERT_EQUAL(
      FAIL_CHECK_SUM,
      checkSeedPhrase("act come effort suffer camp survey warrior heavy shoot "
                      "primary clutch crush open amazing screen patrol group "
                      "space point ten exist slush involve unfold")
          .errorCode);

  // word not in wordlist
  TEST_ASSERT_EQUAL(
      FAIL_WORD,
      checkSeedPhrase("act come effort suffer camp survey warrior heavy shoot "
                      "primary clutch crush open amazing screen patrol group "
                      "space point ten exist slush involve unfolding")
          .errorCode);

  // invarid word numer
  TEST_ASSERT_EQUAL(
      FAIL_WORD_NUMBER,
      checkSeedPhrase("act come effort suffer camp survey").errorCode);

  TEST_ASSERT_EQUAL(
      FAIL_WORD_NUMBER,
      checkSeedPhrase("act come effort suffer camp survey warrior heavy shoot "
                      "primary clutch crush open amazing screen patrol group "
                      "space point ten exist slush involve")
          .errorCode);

  // valid 12 words
  TEST_ASSERT_EQUAL(SUCCESS,
                    checkSeedPhrase("vessel ladder alter error federal sibling "
                                    "chat ability sun glass valve picture")
                        .errorCode);
  // invalid 12 words
  TEST_ASSERT_EQUAL(FAIL_CHECK_SUM,
                    checkSeedPhrase("legal winner thank year wave sausage "
                                    "worth useful legal winner yellow thank")
                        .errorCode);

  // valid 15 words
  TEST_ASSERT_EQUAL(
      SUCCESS,
      checkSeedPhrase("video visa sail push brother strategy antenna budget "
                      "soap tuna school license boat faint symptom")
          .errorCode);

  // valid 18 words
  TEST_ASSERT_EQUAL(
      SUCCESS,
      checkSeedPhrase("legal winner thank year wave sausage worth useful legal "
                      "winner thank year wave sausage worth useful legal will")
          .errorCode);
  // invalid 18 words
  TEST_ASSERT_EQUAL(
      FAIL_CHECK_SUM,
      checkSeedPhrase("legal winner thank year wave sausage worth useful legal "
                      "winner thank year wave sausage worth useful will legal")
          .errorCode);

  // valid 21 words
  TEST_ASSERT_EQUAL(
      SUCCESS,
      checkSeedPhrase(
          "crouch author pumpkin voyage address come believe shop gold vehicle "
          "glare solve speak pink grab oak differ capital ivory address hub")
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