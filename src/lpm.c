#include <stdbool.h>
#include <stdio.h>
#include <string.h>

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
    // TODO: rewrite guide.
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

    printf("LPM has been successfully initialized for you.");
}

void lpm_create()
{
    if (file_exists(user_home) == false) {
        printf("LPM doesn't seem to be initialized.\n");
        return;
    }

    Identity p = {0};
    char nameBuffer[256];
    char emailBuffer[256];
    char phoneBuffer[256];
    char passwordBuffer[256];

    printf("Please fill in the following details.\n\n");

    printf("Identity Name: ");

    /* if (fgets(nameBuffer, sizeof(nameBuffer), stdin) != NULL) {
        nameBuffer[strcspn(nameBuffer, "\n")] = '\0';
        if (strlen(nameBuffer) > 0) {
        p.identityName = strdup(nameBuffer);
        }
    }  */
    if (fgets(nameBuffer, sizeof(nameBuffer), stdin)) {
        nameBuffer[strcspn(nameBuffer, "\n")] = '\0';
        if (*nameBuffer) {
            p.identityName = strdup(nameBuffer);
        }
    }  

    if (p.identityName == NULL) {
        printf("Identity Name is a mandatory field & cannot be left blank.\n");
        return;
    }

    printf("EMAIL: ");
    if (fgets(emailBuffer, sizeof(emailBuffer), stdin) != NULL) {
        emailBuffer[strcspn(emailBuffer, "\n")] = '\0';
            if (strlen(emailBuffer) > 0) {
                p.email = strdup(emailBuffer);
            }
    }

    printf("Phone No.: ");
    if (fgets(phoneBuffer, sizeof(phoneBuffer), stdin) != NULL) {
        phoneBuffer[strcspn(phoneBuffer, "\n")] = '\0';
            if (strlen(phoneBuffer) > 0) {
                p.phoneNumber = strdup(phoneBuffer);
            }
    }

    printf("\nEnter Password (IMMUTABLE): ");
    if (fgets(passwordBuffer, sizeof(passwordBuffer), stdin)) {
        passwordBuffer[strcspn(passwordBuffer, "\n")] = '\0';
        if (*passwordBuffer) {
            p.password = strdup(passwordBuffer);
        }
    }  

    if (p.password == NULL) {
        printf("Password is a mandatory field & cannot be left blank.\n");
        return;
    }
    
    
    FILE *writeIdentity = fopen(user_home, "a");
    if (!writeIdentity) {
        perror("There was some problem accessing files on your machine.");
        return;
    }
    fprintf(writeIdentity,

        "name=%s\n"
        "email=%s\n"
        "phone=%s\n\n",
            
    p.identityName, p.email, p.phoneNumber);
    fclose(writeIdentity);
}

void lpm_invalid()
{
    printf(
    "Invalid Usage: Run `lpm help` to see how to use lightweight password manager."
    );
}