#include "listener.h"
#include "communication.h"

static void listener_switchEventReceive(PPSwitchState_t state);
static void listener_statusEventReceive(PPSwitchStatus_t state);

const char *stateMessageLookup[sizeof(PPSwitchState_t)];
const char *statusMessageLookup[sizeof(PPSwitchStatus_t)];
const char *statusCriticalityLookup[sizeof(PPSwitchStatus_t)];

void listener_init()
{
  communication_register_switch(listener_switchEventReceive);
  communication_register_status(listener_statusEventReceive);

  stateMessageLookup[PPSwitch_On] = "ON";
  stateMessageLookup[PPSwitch_Off] = "OFF";

  statusMessageLookup[PPSwitchStatus_LowBattery] = "LOW BATTERY";
  statusMessageLookup[PPSwitchStatus_Alive] = "ALIVE";

  statusCriticalityLookup[PPSwitchStatus_LowBattery] = "HIGH";
  statusCriticalityLookup[PPSwitchStatus_Alive] = "LOW";
}

static void listener_switchEventReceive(PPSwitchState_t state)
{
  webclient_put("url", stateMessageLookup[state]);
}

static void listener_statusEventReceive(PPSwitchStatus_t status)
{
  // TODO: use the criticality and turn it into JSON, as defined in card #30 on trello
  webclient_post("url2", statusMessageLookup[status]);
}
