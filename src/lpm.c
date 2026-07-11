/*only for testing*/
#include <stdbool.h>
#include <stdio.h>

#include "global.h"

void lpm_help()
{
    printf(
"Usage: lpm <command>\n"
        "\n"
        "Commands: \n"
        "   help                    - Lists all commands of lpm.\n"
        "   init                    - Initializes lpm for current user.\n"
        "   create <identity-name>  - Creates a new identity.\n"
        "   list                    - Lists all identities registered by current user.\n"
        "   open <identity-name>    - Opens specified user and allows you to query saved passwords & usernames.\n"

    );
}

void lpm_guide()
{
    printf(
"LPM - Lightweight Password Manager\n"
        "\n"
        "LPM uses an identity system to categorize your passwords into seperate storage units.\n"
        "Each identity is created with a 3-20 character string that can be associated with an\n"
        "EMAIL & a Phone number (both optionally).\n"
        "\n"
        "This is the initialization of LPM and setups the the environment for saving your passwords\n"
        "safely & reliably.\n"
        "You only need to run the init command ONCE, which you have, there is no need to run this command\n"
        "again.\n"
        "\n"

    );
}

void lpm_init()
{
    if (file_exists(user_home) == true) {
        printf("LPM has already been initialized for you. No need to run init again.\n");
        return;
    }

    FILE *identityfile = fopen(user_home, "w");
    if (identityfile == NULL) {
        printf("Something went wrong accessing files...");
        return;
    }

        
}

void lpm_invalid()
{
    printf(
    "Invalid Usage: Run `lpm help` to see how to use lightweight password manager."
    );
}