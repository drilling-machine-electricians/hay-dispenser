#include <unity.h>
#include <DigitalInputImage.h>

#include "DigitalInputFake.h"

DigitalInputFake *inputFake = NULL;
DigitalInputImage *inputImage = NULL;

void setUp()
{
  inputFake = new DigitalInputFake();
  inputImage = new DigitalInputImage(inputFake);
}

void tearDown(void)
{
  delete inputImage;
  inputImage = NULL;

  delete inputFake;
  inputFake = NULL;
}

void testCreates(void)
{
  TEST_ASSERT_NOT_NULL(inputImage);
}

void testInitialState(void)
{
  inputFake->status = true;
  TEST_ASSERT_FALSE(inputImage->isOn());
}

void testRefreshesImageOn(void)
{
  inputFake->status = true;

  inputImage->refresh();

  TEST_ASSERT_TRUE(inputImage->isOn());
}

void testRefreshesImageOff(void)
{
  inputFake->status = false;

  inputImage->refresh();

  TEST_ASSERT_FALSE(inputImage->isOn());
}

void keepsOnStateIfNotRefreshed(void)
{
  inputFake->status = true;
  inputImage->refresh();

  inputFake->status = false;

  TEST_ASSERT_TRUE(inputImage->isOn());
}

void keepsOffStateIfNotRefreshed(void)
{
  inputFake->status = false;
  inputImage->refresh();

  inputFake->status = true;

  TEST_ASSERT_FALSE(inputImage->isOn());
}

void runTests(void)
{
  UNITY_BEGIN();
  RUN_TEST(testCreates);
  RUN_TEST(testInitialState);
  RUN_TEST(testRefreshesImageOn);
  RUN_TEST(testRefreshesImageOff);
  RUN_TEST(keepsOnStateIfNotRefreshed);
  RUN_TEST(keepsOffStateIfNotRefreshed);
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
