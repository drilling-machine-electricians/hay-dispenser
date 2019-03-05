#include <unity.h>

void setUp()
{
}

void tearDown(void)
{
}

void testCreates(void)
{
  TEST_ASSERT_TRUE(true);
}

void runTests(void)
{
  UNITY_BEGIN();
  RUN_TEST(testCreates);
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
