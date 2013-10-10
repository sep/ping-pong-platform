#include "listener.h"
#include "communication.h"

static void listener_switchEventReceive(PPSwitchState_t state);
static void listener_statusEventReceive(PPSwitchStatus_t state);

void listener_init()
{
  communication_register_switch(listener_switchEventReceive);
  communication_register_status(listener_statusEventReceive);
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

static void listener_statusEventReceive(PPSwitchStatus_t status)
{
  webclient_post("url2", "LOW BATTERY");
}
