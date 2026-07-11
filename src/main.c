#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../libs/libsodium/include/sodium.h"

#include "global.h"

enum OPTION {
    INIT,
    HELP,
    GUIDE,

    INVALID
};

enum OPTION parse_options(const char *arg)
{
    if (strcmp(arg, "help") == 0) {
        return HELP;
    } else if (strcmp(arg, "init") == 0) {
        return INIT;
    } else if (strcmp(arg, "guide") == 0) {
        return GUIDE;
    }

    else {
        return INVALID;
    }
}

int main(int argc, char *argv[])
{
    if (sodium_init() != 0) {
        printf("There was some problem with LPM.");
        abort();
        return -1;
    }

    if (argc < 2) {
        lpm_invalid();
        return -1;
    }

    switch (parse_options(argv[1])) {
        case INIT:
            lpm_init();
        break;
        case HELP:
            lpm_help();
        break;
        case GUIDE:
            lpm_guide();
        break;

        default:
            lpm_invalid();
        break;

    }
}   