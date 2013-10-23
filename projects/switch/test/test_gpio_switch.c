#include "unity.h"
#include "types.h"
#include "switch_types.h"
#include "gpio_switch.h"


PPBOOL didCallDisableWatchdogCallback;

void setUp(void)
{
	didCallDisableWatchdogCallback = PPFalse;
}

void tearDown(void)
{
}

void disableWatchdogCallback(void)
{
	didCallDisableWatchdogCallback = PPTrue;
}

void test_gpio_switch_initialize_should_stop_wdt(void)
{
	switch_functions_s params;
	params.disableWatchdogFunction = disableWatchdogCallback;

	switch_initialize(&params);

	TEST_ASSERT_EQUAL(PPTrue, didCallDisableWatchdogCallback);
}

void test_gpio_switch_initialize_should_register_interrupt(void)
{
    TEST_IGNORE_MESSAGE("Implement me!");
    // Test interupt is registered
}

void test_gpio_switch_initialize_should_set_initial_state(void)
{
    TEST_IGNORE_MESSAGE("Implement me!");
    // Test initial state (off)
}

void test_gpio_switch_handle_button_press_should_call_interrupt_function(void)
{
    TEST_IGNORE_MESSAGE("Implement me!");
    // "Press" button
    // check function called
}
