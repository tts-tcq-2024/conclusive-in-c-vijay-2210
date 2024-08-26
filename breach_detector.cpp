#include "breach_detector.h"

breach_type infer_breach(double value, double lower_limit, double upper_limit) {
    if (value < lower_limit) {
        return TOO_LOW;
    }
    if (value > upper_limit) {
        return TOO_HIGH;
    }
    return NORMAL;
}

breach_type classify_temperature_breach(cooling_type type, double temperature) {
    cooling_config config = get_cooling_config(type);
    return infer_breach(temperature, config.lower_limit, config.upper_limit);
}
