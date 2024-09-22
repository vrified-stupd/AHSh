#include "../include/libs.h"

int delete_recursively(const char *path) {
    struct stat path_stat;

    // Get file or directory information
    if (stat(path, &path_stat) != 0) {
        perror("sh: stat");
        return 1;
    }

    // If it's a directory, open it and delete its contents recursively
    if (S_ISDIR(path_stat.st_mode)) {
        DIR *dir = opendir(path);
        if (dir == NULL) {
            perror("sh: opendir");
            return 1;
        }

        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL) {
            // Skip the "." and ".." entries to avoid infinite recursion
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            // Construct the full path of the directory entry
            char full_path[1024];
            snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

            // Recursively delete the file or directory
            delete_recursively(full_path);
        }

        closedir(dir);

        // Once all contents are deleted, remove the directory itself
        if (rmdir(path) != 0) {
            perror("sh: rmdir");
            return 1;
        }

        printf("Directory '%s' deleted successfully\n", path);
    } else {
        // It's a file, remove it
        if (remove(path) != 0) {
            perror("sh: remove");
            return 1;
        }

        printf("File '%s' deleted successfully\n", path);
    }

    return 0;
}

int sh_del(char **args);

int sh_del(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "sh: expected argument for \"del\" command\n");
        return 1;
    }

    // Concatenate all arguments into one path (in case of spaces in the path)
    char path[1024] = "";
    for (int i = 1; args[i] != NULL; i++) {
        strcat(path, args[i]);
        if (args[i + 1] != NULL) {
            strcat(path, " ");  // Add a space between arguments
        }
    }

    // Call the recursive delete function
    delete_recursively(path);

    return 1;
}