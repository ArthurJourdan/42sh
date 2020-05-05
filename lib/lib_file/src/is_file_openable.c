/*
** EPITECH PROJECT, 2020
** lib_file
** File description:
** is_file_openable.c
*/

#include "my.h"
#include "file.h"

bool is_file_openable(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1) {
        return false;
    }
    close(fd);
    return true;
}

bool is_file_fopenable(char const *filepath)
{
    FILE *fd = fopen(filepath, "r");

    if (!fd) {
        return false;
    }
    fclose(fd);
    return true;
}

bool is_dir_openable(char const *filepath)
{
    DIR *fd = opendir(filepath);

    if (!fd) {
        return false;
    }
    closedir(fd);
    return true;
}
