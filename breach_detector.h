#pragma once

#include "cooling_config.h"
#include "breach_type.h"

breach_type infer_breach(double value, double lower_limit, double upper_limit);
breach_type classify_temperature_breach(cooling_type type, double temperature);
