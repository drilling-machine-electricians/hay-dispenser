#include <unity.h>
#include <InductiveSensor.h>
#include "DigitalInputFake.h"

InductiveSensor *inductiveSensor = NULL;
DigitalInputFake *input = NULL;

void setUp() {
    input = new DigitalInputFake();
    inductiveSensor = new InductiveSensor(input);
}

void tearDown(void) {
    delete input;
    input = NULL;

    delete inductiveSensor;
    inductiveSensor = NULL;
}


void onHighSignalSensorIsNotDampened() {
    input->setValue(true);

    TEST_ASSERT_EQUAL(false, inductiveSensor->isDampened());
}

void onLowSignalSensorIsDampened() {
    input->setValue(false);

    TEST_ASSERT_EQUAL(true, inductiveSensor->isDampened());
}

void runTests() {
    UNITY_BEGIN();
    RUN_TEST(onHighSignalSensorIsNotDampened);
    RUN_TEST(onLowSignalSensorIsDampened);
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