#include "../include/libs.h"

int delete_recursively(const char *path) {
    struct stat path_stat;

    if (stat(path, &path_stat) != 0) {
        perror("sh: stat");
        return 1;
    }

    if (S_ISDIR(path_stat.st_mode)) {
        DIR *dir = opendir(path);
        if (dir == NULL) {
            perror("sh: opendir");
            return 1;
        }

        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            char full_path[1024];
            snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

            delete_recursively(full_path);
        }

        closedir(dir);

        if (rmdir(path) != 0) {
            perror("sh: rmdir");
            return 1;
        }

        printf("Directory '%s' deleted successfully\n", path);
    } else {
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

    char path[1024] = "";
    for (int i = 1; args[i] != NULL; i++) {
        strcat(path, args[i]);
        if (args[i + 1] != NULL) {
            strcat(path, " ");
        }
    }

    delete_recursively(path);

    return 1;
}