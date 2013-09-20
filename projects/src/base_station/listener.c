#include "listener.h"
#include "communication.h"

static void listener_eventReceive(PPEvent_t event, PPSwitchState_t state);

void listener_init()
{
  communication_register(listener_eventReceive);
}

static void listener_eventReceive(PPEvent_t event, PPSwitchState_t state)
{
  switch (state) {
  case PPSwitch_On:
    webclient_put("url", "ON");
    break;
  case PPSwitch_Off:
    webclient_put("url", "OFF");
    break;
  }
}
