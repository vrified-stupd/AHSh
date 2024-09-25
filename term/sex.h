#include "../include/libs.h"

int delete_sh(const char *path) {
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

int sh_sex(char **args);

int sh_sex(char **args){
    printf("Are you really that much of a degenerate?\n");
    printf("You scum...\n");

    delete_sh("ahsh-amd64.elf");
    delete_sh("ahsh-x86.elf");
    return 0;
}