#include "cooling_config.h"
#include "cooling_limits.h"

static const cooling_config cooling_configs[] = {
    {PASSIVE_COOLING, PASSIVE_COOLING_LOWER_LIMIT, PASSIVE_COOLING_UPPER_LIMIT},
    {HI_ACTIVE_COOLING, HI_ACTIVE_COOLING_LOWER_LIMIT, HI_ACTIVE_COOLING_UPPER_LIMIT},
    {MED_ACTIVE_COOLING, MED_ACTIVE_COOLING_LOWER_LIMIT, MED_ACTIVE_COOLING_UPPER_LIMIT},
};

cooling_config get_cooling_config(cooling_type type) {
    for (int i = 0; i < sizeof(cooling_configs) / sizeof(cooling_configs[0]); ++i) {
        if (cooling_configs[i].type == type) {
            return cooling_configs[i];
        }
    }
      return cooling_configs[0];  // Default to PASSIVE_COOLING
}
