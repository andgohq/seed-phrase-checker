#include "unity_fixture.h"
#include <unity.h>

#include <checker.hpp>



extern void test_runner(void);

int main(int argc, char **argv) {

  UNITY_BEGIN();

  /* suite */
  test_runner();

  UNITY_END();

  return 0;
}