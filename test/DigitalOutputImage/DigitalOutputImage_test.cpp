#include <DigitalInputImage.h>
#include <unity.h>

#include "DigitalOutputFake.h"
#include <AbstractDigitalOutput.h>
#include <DigitalOutputImage.h>

DigitalOutputFake *output = NULL;
DigitalOutputImage *outputImage = NULL;

void setUp() {
  output = new DigitalOutputFake();
  outputImage = new DigitalOutputImage(output);
}

void tearDown(void) {
  delete outputImage;
  outputImage = NULL;

  delete output;
  output = NULL;
}

void testCreates(void) { TEST_ASSERT_NOT_NULL(outputImage); }

void testDoesNothingOnCreation(void) {
  TEST_ASSERT_FALSE(output->turnedOn);
  TEST_ASSERT_FALSE(output->turnedOff);
}

void testDoesNothingUntilRefreshIsCalled(void) {
  outputImage->turnOn();

  TEST_ASSERT_FALSE(output->turnedOn);
  TEST_ASSERT_FALSE(output->turnedOff);

  outputImage->turnOff();

  TEST_ASSERT_FALSE(output->turnedOn);
  TEST_ASSERT_FALSE(output->turnedOff);
}

void testTurnsOffOnRefresh(void) {
  outputImage->turnOff();
  outputImage->refresh();

  TEST_ASSERT_FALSE(output->turnedOn);
  TEST_ASSERT_TRUE(output->turnedOff);
}

void testTurnsOnOnRefresh(void) {
  outputImage->turnOn();
  outputImage->refresh();

  TEST_ASSERT_TRUE(output->turnedOn);
  TEST_ASSERT_FALSE(output->turnedOff);
}

void runTests(void) {
  UNITY_BEGIN();
  RUN_TEST(testCreates);
  RUN_TEST(testDoesNothingOnCreation);
  RUN_TEST(testDoesNothingUntilRefreshIsCalled);
  RUN_TEST(testTurnsOffOnRefresh);
  RUN_TEST(testTurnsOnOnRefresh);
  UNITY_END();
}

void setup() { runTests(); }

void loop() {}

int main(int argc, char **argv) {
  runTests();
  return 0;
}
