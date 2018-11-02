#include <unity.h>

void shouldTest() {
    TEST_ASSERT_EQUAL(true, true);
}

void runTests() {
    UNITY_BEGIN();
    RUN_TEST(shouldTest);
    UNITY_END();
}

void setup() {
    runTests();
}

void loop() {
}

int main(int argc, char **argv) {
    runTests();
    return 0;
}
