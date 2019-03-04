#include <unity.h>
#include <LinearMotor.h>
#include "RelaisFake.h"

LinearMotor *motor = NULL;
RelaisFake *forward;
RelaisFake *backward;

void setUp()
{
  forward = new RelaisFake();
  backward = new RelaisFake();
  motor = new LinearMotor();
}

void tearDown(void)
{
  delete motor;
  motor = NULL;
  delete forward;
  forward = NULL;
  delete backward;
  backward = NULL;
}

void testCreates(void)
{
  TEST_ASSERT_NOT_NULL(motor);
}

void testInitialState(void)
{
  TEST_ASSERT_FALSE(forward->turnedOff);
  TEST_ASSERT_FALSE(forward->turnedOn);
  TEST_ASSERT_FALSE(backward->turnedOff);
  TEST_ASSERT_FALSE(backward->turnedOn);
}

void runTests()
{
  UNITY_BEGIN();
  RUN_TEST(testCreates);
  RUN_TEST(testInitialState);
  UNITY_END();
}

void setup()
{
  runTests();
}

void loop()
{
}

int main(int argc, char **argv)
{
  runTests();
  return 0;
}
