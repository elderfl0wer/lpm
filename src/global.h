#include <stdbool.h>

#ifndef GLOBAL_H
#define GLOBAL_H

typedef struct {
    char *identityName;
    char *email;
    char phoneNumber[16];
} Identity;

extern char user_home[512];

void lpm_help();
void lpm_init();
void lpm_guide();

void lpm_invalid();

bool file_exists(const char *filename);


#endif