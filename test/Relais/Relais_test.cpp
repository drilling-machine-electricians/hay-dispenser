#include <unity.h>
#include <Relais.h>
#include "DigitalOutputMock.h"

Relais *relais = NULL;
DigitalOutputMock *digitalOutputMock = NULL;

void setUp() {
    digitalOutputMock = new DigitalOutputMock();
    relais = new Relais(digitalOutputMock);
}

void tearDown() {
    delete relais;
    relais = NULL;

    delete digitalOutputMock;
    digitalOutputMock = NULL;
}

void initializes() {
    TEST_ASSERT_NOT_NULL(relais);
}

void turnsOn() {
    relais->turnOn();

    TEST_ASSERT_EQUAL(1, digitalOutputMock->calls);
    TEST_ASSERT_EQUAL(false, digitalOutputMock->callValue);
}

void turnsOff() {
    relais->turnOff();

    TEST_ASSERT_EQUAL(1, digitalOutputMock->calls);
    TEST_ASSERT_EQUAL(true, digitalOutputMock->callValue);
}

void runTests() {
    UNITY_BEGIN();
    RUN_TEST(initializes);
    RUN_TEST(turnsOn);
    RUN_TEST(turnsOff);
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