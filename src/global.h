#include <stdbool.h>

#ifndef GLOBAL_H
#define GLOBAL_H

#if defined (_WIN32) || defined (_WIN32_) || defined (WIN32)
    #define PLATFORM_WINDOWS 1  
    #include <Windows.h>

    #define WIN32_LEAN_AND_MEAN
#else
    #define PLATFORM_POSIX
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <unistd.h>
    #include <errno.h>
#endif

typedef struct {
    char *identityName;
    char *email;
    char *phoneNumber;
    char *password;
} Identity;

/*  ~/.lpm for both Windows & Linux is held in this variable.  */
extern char user_home[512];
extern char user_data_dir[1024];

void lpm_help();
void lpm_init();
void lpm_guide();
void lpm_create();

void lpm_invalid();

void set_user_home();
bool file_exists(const char *filename);
bool folder_exists(const char *foldername);
void set_user_data_dir();


#endif