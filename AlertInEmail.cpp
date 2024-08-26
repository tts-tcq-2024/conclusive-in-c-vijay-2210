#include "AlertInEmail.h"
#include <stdio.h>

void send_to_email(breach_type breach) {
    const char* recipient = "a.b@c.com";
    printf("To: %s\n", recipient);

    const char* messages[] = {
        "Hi, the temperature is too low\n",
        "Hi, the temperature is too high\n"
    };

    if (breach != NORMAL) {
        printf("%s", messages[breach - 1]);
    }
}
