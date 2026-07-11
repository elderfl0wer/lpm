#include <stdbool.h>

#ifndef GLOBAL_H
#define GLOBAL_H

typedef struct {
    char *identityName;
    char *email;
    char *phoneNumber;
    char *password;
} Identity;

/*  ~/.lpm for both Windows & Linux is held in this variable.  */
extern char user_home[512];

void lpm_help();
void lpm_init();
void lpm_guide();
void lpm_create();

void lpm_invalid();

void set_user_home();
bool file_exists(const char *filename);


#endif