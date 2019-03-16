#include "DigitalInputFake.h"
#include "DigitalOutputFake.h"
#include <DigitalInputImage.h>
#include <ProcessImageController.h>
#include <unity.h>

ProcessImageController *controller = NULL;
DigitalOutputFake *output = NULL;
DigitalInputFake *input = NULL;
AbstractDigitalInput *image1 = NULL;
AbstractDigitalInput *image2 = NULL;
AbstractDigitalInput *image3 = NULL;
AbstractDigitalInput *image4 = NULL;

AbstractDigitalOutput *outputImage = NULL;

void setUp() {
  controller = new ProcessImageController();
  input = new DigitalInputFake();
  output = new DigitalOutputFake();
}

void tearDown(void) {
  delete controller;
  controller = NULL;

  delete input;
  input = NULL;

  delete image1;
  image1 = NULL;

  delete image2;
  image2 = NULL;

  delete image3;
  image3 = NULL;

  delete image4;
  image4 = NULL;

  delete outputImage;
  outputImage = NULL;
}

void testCreates(void) { TEST_ASSERT_NOT_NULL(controller); }

void testRegistersInput(void) {
  input->status = true;

  image1 = controller->registerInput(input);

  TEST_ASSERT_FALSE(image1->isOn())
}

void testReadInputs(void) {
  input->status = true;

  image1 = controller->registerInput(input);

  controller->read();

  TEST_ASSERT_TRUE(image1->isOn())
}

void testReadMultipleInputs(void) {
  input->status = true;

  image1 = controller->registerInput(input);
  image2 = controller->registerInput(input);
  image3 = controller->registerInput(input);
  image4 = controller->registerInput(input);

  controller->read();

  TEST_ASSERT_TRUE(image1->isOn())
  TEST_ASSERT_TRUE(image2->isOn())
  TEST_ASSERT_TRUE(image3->isOn())
  TEST_ASSERT_TRUE(image4->isOn())
}

void testRegistersOutput(void) {
  input->status = true;

  outputImage = controller->registerOutput(output);

  TEST_ASSERT_NOT_NULL(outputImage);
}

void runTests(void) {
  UNITY_BEGIN();
  RUN_TEST(testCreates);
  RUN_TEST(testRegistersInput);
  RUN_TEST(testReadInputs);
  RUN_TEST(testReadMultipleInputs);
  RUN_TEST(testRegistersOutput);
  UNITY_END();
}

void setup() { runTests(); }

void loop() {}

int main(int argc, char **argv) {
  runTests();
  return 0;
}
