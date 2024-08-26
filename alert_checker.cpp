#include "TemperatureAlert_checker.h"
#include "breach_detector.h"
#include "alert_to_controller.h"
#include "AlertInEmail.h"
#include "alert_function.h" 

static const struct {
    alert_target target;
    alert_function func;
} alert_mappings[] = {
    {TO_CONTROLLER, send_to_controller},
    {TO_EMAIL, send_to_email}
};

void check_and_alert(alert_target target, battery_character battery, double temperature) {
    breach_type breach = classify_temperature_breach(battery.type, temperature);

    for (int i = 0; i < sizeof(alert_mappings) / sizeof(alert_mappings[0]); ++i) {
        if (alert_mappings[i].target == target) {
            alert_mappings[i].func(breach);
            break;
        }
    }
}
