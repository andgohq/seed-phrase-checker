#include <iostream>
#include <string>

#include "unity_fixture.h"
#include <unity.h>

#include <checker.hpp>

TEST_SETUP(checker) {}

TEST_TEAR_DOWN(checker) {}

void test_checkLastWord() {
  TEST_ASSERT_EQUAL(true, checkLastWord("act"));
  TEST_ASSERT_EQUAL(true, checkLastWord(" act"));
  TEST_ASSERT_EQUAL(true, checkLastWord("  act  "));
  TEST_ASSERT_EQUAL(true, checkLastWord(" aaa act  "));
  TEST_ASSERT_EQUAL(false, checkLastWord("actt"));
  TEST_ASSERT_EQUAL(false, checkLastWord(" actt"));
  TEST_ASSERT_EQUAL(false, checkLastWord(" actt "));
  TEST_ASSERT_EQUAL(false, checkLastWord(" act  actt "));
}

void test_function_should_doBlahAndBlah(void) {
  // test stuff
}

void test_runner(void) { RUN_TEST(test_checkLastWord); }