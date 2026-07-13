#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// #include <Windows.h>

/* Includes Windows.h */
#include "global.h"

char user_home[512] = {0};
char user_data_dir[1024] = {0};

void set_user_home()
{
    const char *file_path = getenv("HOME");
    if (file_path == NULL) {
        file_path = getenv("USERPROFILE");
    }

    snprintf(user_home, sizeof(user_home), "%s/.lpm", file_path);
}

bool file_exists(const char *filename)
{
    FILE *file = fopen(user_home, "r");
    if (file == NULL) {
        return false;
    } else {
        fclose(file);
        return true;
    }
}

bool folder_exists(const char *foldername)
{
#ifdef _WIN32
    DWORD attributes = GetFileAttributesA(foldername);

    if (attributes == INVALID_FILE_ATTRIBUTES) {
        return false;
    }

    return (attributes & FILE_ATTRIBUTE_DIRECTORY) != 0;

#else // UNIX
    struct stat stats;

    if (stat(foldername, &stats) == -1) {
        return false; 
    }

    return S_ISDIR(stats.st_mode);
#endif
}

void set_user_data_dir()
{
#ifdef _WIN32
    const char *local_app_data = getenv("LOCALAPPDATA");
    snprintf(user_data_dir, sizeof(user_data_dir), "%s\\LPM", local_app_data);

#else
    const char *app_data = getenv("HOME");
    snprintf(user_data_dir, sizeof(user_data_dir), "%s\\.config\\share\\LPM", app_data);
#endif
}