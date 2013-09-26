#include "unity.h"

#include "types.h"
#include "listener.h"

#include "mock_communication.h"
#include "mock_webclient.h"

#define REGISTRATION_COUNT 2

#ifndef NULL
#define NULL 0
#endif

static void communication_register_stub(PPEvent_t eventType, PPListenerCallback_cb callback, int numCalls);
static PPBOOL communication_register_hasBeenCalled;
static PPEvent_t communication_register_eventType[REGISTRATION_COUNT];
static PPListenerCallback_cb communication_register_registeredCallback[REGISTRATION_COUNT];
static int whateverCounter = 0;

void setUp(void)
{
  int i;
  for(i=0; i<REGISTRATION_COUNT-1; ++i)
  {
    communication_register_eventType[i] = -1;
    communication_register_registeredCallback[i] = NULL;
  }
  communication_register_hasBeenCalled = PPFalse;
  whateverCounter = 0;
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
  TEST_ASSERT_EQUAL(PPEvent_Switch, communication_register_eventType[0]);
}

void test_listener_should_register_callback_for_status_event(void)
{
  communication_register_StubWithCallback(communication_register_stub);

  listener_init();

  TEST_ASSERT_EQUAL(PPTrue, communication_register_hasBeenCalled);
  TEST_ASSERT_EQUAL(PPEvent_Status, communication_register_eventType[1]);
}

void test_listener_should_execute_webservice_call_on_callback_for_switch_on(void)
{
  communication_register_StubWithCallback(communication_register_stub);
  webclient_put_Expect("url", "ON");

  listener_init();

  communication_register_registeredCallback[0](PPSwitch_On);
}

void test_listener_should_execute_webservice_call_on_callback_for_switch_off(void)
{
  communication_register_StubWithCallback(communication_register_stub);
  webclient_put_Expect("url", "OFF");

  listener_init();

  communication_register_registeredCallback[0](PPSwitch_Off);
}

void test_listener_should_execute_webservice_call_on_callback_for_status(void)
{
  communication_register_StubWithCallback(communication_register_stub);
  webclient_post_Expect("url2", "LOW BATTERY");

  listener_init();

  communication_register_registeredCallback[1](PPStatus_LowBattery);
}

static void communication_register_stub(PPEvent_t eventType, PPListenerCallback_cb callback, int numCalls)
{
  
  communication_register_eventType[whateverCounter] = eventType;
  communication_register_registeredCallback[whateverCounter] = callback;
  whateverCounter++;

  communication_register_hasBeenCalled = PPTrue;
}
