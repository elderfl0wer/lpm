#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "global.h"

char user_home[512];

bool file_exists(const char *filename)
{
    const char *file_path = getenv("HOME");
    if (file_path == NULL) {
        file_path = getenv("USERPROFILE");
    }

    snprintf(user_home, sizeof(user_home), "%s/.lpm", file_path);

    FILE *file = fopen(user_home, "r");
    if (file == NULL) {
        return false;
    } else {
        fclose(file);
        return true;
    }
}