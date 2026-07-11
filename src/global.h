#include <stdio.h>
#include <stdbool.h>

#ifndef GLOBAL_H
#define GLOBAL_H
extern char user_home[512];

void lpm_help();
void lpm_init();
void lpm_invalid();

bool file_exists(const char *filename);


#endif