#include "gpio_switch.h"


void switch_initialize(switch_functions_s *params)
{
    (*params).disableWatchdogFunction();
}
