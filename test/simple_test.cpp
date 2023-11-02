#include "Arduino.h"
#include "unity.h"

void setUp() {
	pinMode(4, OUTPUT);
}

void tearDown() {

}

void test_digitalwrite() {
	digitalWrite(4, HIGH);
	TEST_ASSERT(digitalRead(4) == HIGH);
	digitalWrite(4, LOW);
	TEST_ASSERT(digitalRead(4) == LOW);
}

void setup(void) {
	UNITY_BEGIN(); 
	RUN_TEST(test_digitalwrite);
	UNITY_END();
}

void loop() {

}
