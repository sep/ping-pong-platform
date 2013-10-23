#include "unity.h"

#include "types.h"
#include "listener.h"

#include "mock_communication.h"
#include "mock_webclient.h"

#ifndef NULL
#define NULL 0
#endif

static void communication_register_switch_stub(PPSwitchListenerCallback_cb callback, int numCalls);
static void communication_register_status_stub(PPStatusListenerCallback_cb callback, int numCalls);
static PPBOOL communication_register_switch_hasBeenCalled;
static PPBOOL communication_register_status_hasBeenCalled;

static PPSwitchListenerCallback_cb communication_register_switch_registeredCallback;
static PPStatusListenerCallback_cb communication_register_status_registeredCallback;

char *expected_state_url = "http://app.sep.com/pong_status/switch";
char *expected_status_url = "http://app.sep.com/pong_status/status";

void setUp(void)
{
  communication_register_switch_registeredCallback = NULL;
  communication_register_status_registeredCallback = NULL;

  communication_register_switch_hasBeenCalled = PPFalse;
  communication_register_status_hasBeenCalled = PPFalse;
}

void tearDown(void)
{
  // empty
}

void test_listener_should_register_callback_for_switch_event(void)
{
  communication_register_switch_StubWithCallback(communication_register_switch_stub);
  communication_register_status_StubWithCallback(communication_register_status_stub);

  listener_init();

  TEST_ASSERT_EQUAL(PPTrue, communication_register_switch_hasBeenCalled);
}

void test_listener_should_register_callback_for_status_event(void)
{
  communication_register_switch_StubWithCallback(communication_register_switch_stub);
  communication_register_status_StubWithCallback(communication_register_status_stub);

  listener_init();

  TEST_ASSERT_EQUAL(PPTrue, communication_register_status_hasBeenCalled);
}

void test_listener_should_execute_webservice_call_on_callback_for_switch_on(void)
{
  communication_register_switch_StubWithCallback(communication_register_switch_stub);
  communication_register_status_StubWithCallback(communication_register_status_stub);

  webclient_put_Expect(expected_state_url, "ON");

  listener_init();

  communication_register_switch_registeredCallback(PPSwitch_On);
}

void test_listener_should_execute_webservice_call_on_callback_for_switch_off(void)
{
  communication_register_switch_StubWithCallback(communication_register_switch_stub);
  communication_register_status_StubWithCallback(communication_register_status_stub);

  webclient_put_Expect(expected_state_url, "OFF");

  listener_init();

  communication_register_switch_registeredCallback(PPSwitch_Off);
}

void test_listener_should_execute_webservice_call_on_callback_for_low_battery_status(void)
{
  communication_register_switch_StubWithCallback(communication_register_switch_stub);
  communication_register_status_StubWithCallback(communication_register_status_stub);

  webclient_post_Expect(expected_status_url, "LOW BATTERY");

  listener_init();

  communication_register_status_registeredCallback(PPSwitchStatus_LowBattery);
}

void test_listener_should_execute_webservice_call_on_callback_for_alive_status(void)
{
  communication_register_switch_StubWithCallback(communication_register_switch_stub);
  communication_register_status_StubWithCallback(communication_register_status_stub);

  webclient_post_Expect(expected_status_url, "ALIVE");

  listener_init();

  communication_register_status_registeredCallback(PPSwitchStatus_Alive);
}

static void communication_register_switch_stub(PPSwitchListenerCallback_cb callback, int numCalls)
{
  communication_register_switch_registeredCallback = callback;
  communication_register_switch_hasBeenCalled = PPTrue;
}

static void communication_register_status_stub(PPStatusListenerCallback_cb callback, int numCalls)
{
  communication_register_status_registeredCallback = callback;
  communication_register_status_hasBeenCalled = PPTrue;
}
