#pragma once

#include "alert_target.h"
#include "battery_character.h"

void check_and_alert(alert_target target, battery_character battery, double temperature);
