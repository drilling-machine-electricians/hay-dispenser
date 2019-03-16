#include <DigitalInputImage.h>
#include <unity.h>

#include "DigitalOutputImage.h"

DigitalOutputImage *outputImage = NULL;

void setUp() { outputImage = new DigitalOutputImage(); }

void tearDown(void) {}

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
