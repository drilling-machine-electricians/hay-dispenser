#include <unity.h>
#include <ProcessImageController.h>
#include <DigitalInputImage.h>
#include "DigitalInputFake.h"

ProcessImageController *controller = NULL;
DigitalInputFake *input1 = NULL;
DigitalInputFake *input2 = NULL;
DigitalInputImage *image1 = NULL;
DigitalInputImage *image2 = NULL;
DigitalInputImage *image3 = NULL;
DigitalInputImage *image4 = NULL;

void setUp()
{
  controller = new ProcessImageController();
  input1 = new DigitalInputFake();
  input2 = new DigitalInputFake();
}

void tearDown(void)
{
  delete controller;
  controller = NULL;

  delete input1;
  input1 = NULL;

  delete input2;
  input2 = NULL;

  delete image1;
  image1 = NULL;

  delete image2;
  image2 = NULL;

  delete image3;
  image3 = NULL;

  delete image4;
  image4 = NULL;
}

void testCreates(void)
{
  TEST_ASSERT_NOT_NULL(controller);
}

void testRegistersInput(void)
{
  input1->status = true;

  image1 = controller->registerInput(input1);

  TEST_ASSERT_FALSE(image1->isOn())
}

void testReadInputs(void)
{
  input1->status = true;

  image1 = controller->registerInput(input1);

  controller->read();

  TEST_ASSERT_TRUE(image1->isOn())
}

void testReadMultipleInputs(void)
{
  input1->status = true;

  image1 = controller->registerInput(input1);
  image2 = controller->registerInput(input1);
  image3 = controller->registerInput(input1);
  image4 = controller->registerInput(input1);

  controller->read();

  TEST_ASSERT_TRUE(image1->isOn())
  TEST_ASSERT_TRUE(image2->isOn())
  TEST_ASSERT_TRUE(image3->isOn())
  TEST_ASSERT_TRUE(image4->isOn())
}

void runTests(void)
{
  UNITY_BEGIN();
  RUN_TEST(testCreates);
  RUN_TEST(testRegistersInput);
  RUN_TEST(testReadInputs);
  RUN_TEST(testReadMultipleInputs);
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
