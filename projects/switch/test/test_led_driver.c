#include "unity.h"
#include "types.h"
#include "led_driver.c"

led_addresses_s params;

void setUp(void)
{
	params.direction = 0;
	params.output = 0;
}

void tearDown(void)
{
	is_initialized = PPFalse;
}

void test_led_driver_led_initialize_should_setup_direction(void)
{
	led_initialize(&params);

	TEST_ASSERT_EQUAL(LED_GREEN_PIN_VALUE + LED_RED_PIN_VALUE, params.direction & (LED_GREEN_PIN_VALUE + LED_RED_PIN_VALUE));
}

void test_led_driver_led_initialize_should_have_both_leds_turned_off(void)
{
	led_initialize(&params);

	TEST_ASSERT_EQUAL(0, params.output);
}

void test_led_driver_set_led_color_should_fail_if_uninitialized(void)
{
	TEST_ASSERT_EQUAL(PPFalse, set_led_color(LED_OFF));
}

void test_led_driver_set_led_color_should_succeed_if_initialized(void)
{
	led_initialize(&params);
	TEST_ASSERT_EQUAL(PPTrue, set_led_color(LED_OFF));
}

void test_led_driver_set_led_color_should_actually_do_it(void)
{
    TEST_IGNORE_MESSAGE("Implement me!");
}
