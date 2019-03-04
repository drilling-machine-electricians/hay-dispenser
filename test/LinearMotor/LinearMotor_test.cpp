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
  motor = new LinearMotor(forward, backward);
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

void testInitialState(void)
{
  TEST_ASSERT_TRUE(motor->isStopped())
  TEST_ASSERT_FALSE(motor->isMovingForward());
  TEST_ASSERT_FALSE(motor->isMovingBackward());

  TEST_ASSERT_FALSE(forward->turnedOff);
  TEST_ASSERT_FALSE(forward->turnedOn);
  TEST_ASSERT_FALSE(backward->turnedOff);
  TEST_ASSERT_FALSE(backward->turnedOn);
}

void testMoveForward(void)
{
  motor->forward();

  TEST_ASSERT_TRUE(motor->isMovingForward());
  TEST_ASSERT_FALSE(motor->isMovingBackward());
  TEST_ASSERT_FALSE(motor->isStopped())

  TEST_ASSERT_FALSE(forward->turnedOff);
  TEST_ASSERT_TRUE(forward->turnedOn);
  TEST_ASSERT_FALSE(backward->turnedOff);
  TEST_ASSERT_FALSE(backward->turnedOn);
}

void testMoveBackward(void)
{
  motor->backward();

  TEST_ASSERT_FALSE(motor->isMovingForward());
  TEST_ASSERT_TRUE(motor->isMovingBackward());
  TEST_ASSERT_FALSE(motor->isStopped())

  TEST_ASSERT_FALSE(forward->turnedOff);
  TEST_ASSERT_FALSE(forward->turnedOn);
  TEST_ASSERT_FALSE(backward->turnedOff);
  TEST_ASSERT_TRUE(backward->turnedOn);
}

void resetFakes()
{
  forward->turnedOff = false;
  forward->turnedOn = false;
  backward->turnedOff = false;
  backward->turnedOn = false;
}

void testStopWhenMovingForward(void)
{
  motor->forward();
  resetFakes();

  motor->stop();

  TEST_ASSERT_FALSE(motor->isMovingForward());
  TEST_ASSERT_FALSE(motor->isMovingBackward());

  TEST_ASSERT_TRUE(forward->turnedOff);
  TEST_ASSERT_FALSE(forward->turnedOn);
  TEST_ASSERT_FALSE(backward->turnedOff);
  TEST_ASSERT_FALSE(backward->turnedOn);
}

void testStopWhenMovingBackward(void)
{
  motor->backward();
  resetFakes();

  motor->stop();

  TEST_ASSERT_TRUE(motor->isStopped())
  TEST_ASSERT_FALSE(motor->isMovingForward());
  TEST_ASSERT_FALSE(motor->isMovingBackward());

  TEST_ASSERT_FALSE(forward->turnedOff);
  TEST_ASSERT_FALSE(forward->turnedOn);
  TEST_ASSERT_TRUE(backward->turnedOff);
  TEST_ASSERT_FALSE(backward->turnedOn);
}

void testStopWhenNotMoving(void)
{
  motor->stop();

  TEST_ASSERT_TRUE(motor->isStopped())
  TEST_ASSERT_FALSE(motor->isMovingForward());
  TEST_ASSERT_FALSE(motor->isMovingBackward());

  TEST_ASSERT_FALSE(forward->turnedOff);
  TEST_ASSERT_FALSE(forward->turnedOn);
  TEST_ASSERT_FALSE(backward->turnedOff);
  TEST_ASSERT_FALSE(backward->turnedOn);
}

void testTryToMoveBackwardWhenMovingForward(void)
{
  motor->forward();
  resetFakes();

  motor->backward();

  TEST_ASSERT_FALSE(motor->isStopped())
  TEST_ASSERT_TRUE(motor->isMovingForward());
  TEST_ASSERT_FALSE(motor->isMovingBackward());

  TEST_ASSERT_FALSE(forward->turnedOff);
  TEST_ASSERT_FALSE(forward->turnedOn);
  TEST_ASSERT_FALSE(backward->turnedOff);
  TEST_ASSERT_FALSE(backward->turnedOn);
}

void testTryToMoveForwardWhenMovingBackward(void)
{
  motor->backward();
  resetFakes();

  motor->forward();

  TEST_ASSERT_FALSE(motor->isStopped())
  TEST_ASSERT_FALSE(motor->isMovingForward());
  TEST_ASSERT_TRUE(motor->isMovingBackward());

  TEST_ASSERT_FALSE(forward->turnedOff);
  TEST_ASSERT_FALSE(forward->turnedOn);
  TEST_ASSERT_FALSE(backward->turnedOff);
  TEST_ASSERT_FALSE(backward->turnedOn);
}

void testMoveForwardWhenMovingForward(void)
{
  motor->forward();
  resetFakes();

  motor->forward();

  TEST_ASSERT_FALSE(motor->isStopped())
  TEST_ASSERT_TRUE(motor->isMovingForward());
  TEST_ASSERT_FALSE(motor->isMovingBackward());

  TEST_ASSERT_FALSE(forward->turnedOff);
  TEST_ASSERT_FALSE(forward->turnedOn);
  TEST_ASSERT_FALSE(backward->turnedOff);
  TEST_ASSERT_FALSE(backward->turnedOn);
}

void testMoveBackwardWhenMovingBackward(void)
{
  motor->backward();
  resetFakes();

  motor->backward();

  TEST_ASSERT_FALSE(motor->isStopped())
  TEST_ASSERT_FALSE(motor->isMovingForward());
  TEST_ASSERT_TRUE(motor->isMovingBackward());

  TEST_ASSERT_FALSE(forward->turnedOff);
  TEST_ASSERT_FALSE(forward->turnedOn);
  TEST_ASSERT_FALSE(backward->turnedOff);
  TEST_ASSERT_FALSE(backward->turnedOn);
}

void testChangeDirectionFromBackwardToForward(void)
{
  motor->backward();
  motor->stop();

  motor->forward();
  TEST_ASSERT_TRUE(motor->isMovingForward());
}

void testChangeDirectionFromForwardToBackward(void)
{
  motor->forward();
  motor->stop();

  motor->backward();
  TEST_ASSERT_TRUE(motor->isMovingBackward());
}

void runTests()
{
  UNITY_BEGIN();
  RUN_TEST(testInitialState);
  RUN_TEST(testMoveForward);
  RUN_TEST(testMoveBackward);
  RUN_TEST(testStopWhenMovingForward);
  RUN_TEST(testStopWhenMovingBackward);
  RUN_TEST(testStopWhenNotMoving);
  RUN_TEST(testTryToMoveBackwardWhenMovingForward);
  RUN_TEST(testTryToMoveForwardWhenMovingBackward);
  RUN_TEST(testMoveForwardWhenMovingForward);
  RUN_TEST(testMoveBackwardWhenMovingBackward);
  RUN_TEST(testChangeDirectionFromBackwardToForward);
  RUN_TEST(testChangeDirectionFromForwardToBackward);
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
