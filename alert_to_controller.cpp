#include "alert_to_controller.h"
#include <stdio.h>

void send_to_controller(breach_type breach) {
    const unsigned short header = 0xfeed;
    printf("%x : %x\n", header, breach);
}
