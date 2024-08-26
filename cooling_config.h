#pragma once

typedef enum {
    PASSIVE_COOLING,
    HI_ACTIVE_COOLING,
    MED_ACTIVE_COOLING
} cooling_type;

typedef struct {
    cooling_type type;
    int lower_limit;
    int upper_limit;
} cooling_config;

cooling_config get_cooling_config(cooling_type type);
