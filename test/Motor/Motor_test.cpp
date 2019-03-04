#include <unity.h>

void setUp()
{
}

void tearDown(void)
{
}

void testSomething(void)
{
}

void runTests()
{
  UNITY_BEGIN();
  RUN_TEST(testSomething);
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
