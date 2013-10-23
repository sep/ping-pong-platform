#include "listener.h"
#include "communication.h"
#include <string.h>

static void listener_switchEventReceive(PPSwitchState_t state);
static void listener_statusEventReceive(PPSwitchStatus_t state);

const char *stateMessageLookup[sizeof(PPSwitchState_t)];
const char *statusMessageLookup[sizeof(PPSwitchStatus_t)];
const char *statusCriticalityLookup[sizeof(PPSwitchStatus_t)];

// Max url size arbitrarily set to 100
char state_url[100];
char status_url[100];

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

  strcpy(state_url, "http://app.sep.com/pong_status/switch");
  strcpy(status_url, "http://app.sep.com/pong_status/status");	
}

static void listener_switchEventReceive(PPSwitchState_t state)
{
  webclient_put(state_url, stateMessageLookup[state]);
}

static void listener_statusEventReceive(PPSwitchStatus_t status)
{
  // TODO: use the criticality and turn it into JSON, as defined in card #30 on trello
  webclient_post(status_url, statusMessageLookup[status]);
}
