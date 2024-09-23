#include "../include/libs.h"

int sh_list(char **args);

// Comparison function for sorting directory entries
int compare(const void *a, const void *b) {
    struct dirent **entryA = (struct dirent **)a;
    struct dirent **entryB = (struct dirent **)b;
    return strcmp((*entryA)->d_name, (*entryB)->d_name);
}

// Function to list files and directories
int sh_list(char **args) {
    DIR *dir;
    struct dirent **entry_list;
    int entry_count;
    char *dir_path = ".";  // Default to current directory if no path is provided

    // If a directory path is given as an argument, use it
    if (args[1] != NULL) {
        dir_path = args[1];
    }

    // Open the directory
    dir = opendir(dir_path);
    if (dir == NULL) {
        perror("sh: opendir");
        return 1;
    }

    // Read all entries in the directory
    entry_count = scandir(dir_path, &entry_list, NULL, alphasort);
    if (entry_count < 0) {
        perror("sh: scandir");
        closedir(dir);
        return 1;
    }

    // Print each entry, skipping "." and ".."
    for (int i = 0; i < entry_count; i++) {
        if (strcmp(entry_list[i]->d_name, ".") != 0 && strcmp(entry_list[i]->d_name, "..") != 0) {
            char full_path[PATH_MAX];
            snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry_list[i]->d_name);
            
            struct stat statbuf;
            if (stat(full_path, &statbuf) == 0) {
                if (S_ISDIR(statbuf.st_mode)) {
                    printf("/%s\n", entry_list[i]->d_name); // Add '/' before the directory name
                } else {
                    printf("%s\n", entry_list[i]->d_name);  // Just print for files
                }
            } else {
                perror("sh: stat");
            }
        }
        free(entry_list[i]);
    }

    free(entry_list);
    closedir(dir);

    return 1;
}