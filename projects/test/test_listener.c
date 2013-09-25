#include "unity.h"

#include "types.h"
#include "listener.h"

#include "mock_communication.h"
#include "mock_webclient.h"

static void communication_register_stub(PPEvent_t eventType, PPListenerCallback_cb callback, int numCalls);
static PPBOOL communication_register_hasBeenCalled;
static PPListenerCallback_cb communication_register_registeredCallback;

void setUp(void)
{
  communication_register_hasBeenCalled = PPFalse;
}

void tearDown(void)
{
  // empty
}

void test_listener_should_register_callback_for_switch_event(void)
{
  communication_register_StubWithCallback(communication_register_stub);

  listener_init();

  TEST_ASSERT_EQUAL(PPTrue, communication_register_hasBeenCalled);
}

void test_listener_should_execute_webservice_call_on_callback_for_switch_on(void)
{
  communication_register_StubWithCallback(communication_register_stub);
  webclient_put_Expect("url", "ON");

  listener_init();

  communication_register_registeredCallback(PPSwitch_On);
}

void test_listener_should_execute_webservice_call_on_callback_for_switch_off(void)
{
  communication_register_StubWithCallback(communication_register_stub);
  webclient_put_Expect("url", "OFF");

  listener_init();

  communication_register_registeredCallback(PPSwitch_Off);
}

static void communication_register_stub(PPEvent_t eventType, PPListenerCallback_cb callback, int numCalls)
{
  communication_register_registeredCallback = callback;
  communication_register_hasBeenCalled = PPTrue;
}
