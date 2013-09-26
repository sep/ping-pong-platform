#include "listener.h"
#include "communication.h"

static void listener_switchEventReceive(PPSwitchState_t state);
static void listener_statusEventReceive(PPSwitchState_t state);

void listener_init()
{
  communication_register(PPEvent_Switch, listener_switchEventReceive);
  communication_register(PPEvent_Status, listener_statusEventReceive);
}

static void listener_switchEventReceive(PPSwitchState_t state)
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

static void listener_statusEventReceive(PPSwitchState_t state)
{
  webclient_post("url2", "LOW BATTERY");
}
