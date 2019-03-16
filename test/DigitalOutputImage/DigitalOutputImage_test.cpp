#include <DigitalInputImage.h>
#include <unity.h>

#include "DigitalOutputFake.h"
#include <AbstractDigitalOutput.h>
#include <DigitalOutputImage.h>

AbstractDigitalOutput *output = NULL;
DigitalOutputImage *outputImage = NULL;

void setUp() {
  output = new DigitalOutputFake();
  outputImage = new DigitalOutputImage();
}

void tearDown(void) {
  delete outputImage;
  outputImage = NULL;

  delete output;
  output = NULL;
}

void testCreates(void) { TEST_ASSERT_NOT_NULL(outputImage); }

void runTests(void) {
  UNITY_BEGIN();
  RUN_TEST(testCreates);
  UNITY_END();
}

void setup() { runTests(); }

void loop() {}

int main(int argc, char **argv) {
  runTests();
  return 0;
}
