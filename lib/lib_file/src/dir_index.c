/*
** EPITECH PROJECT, 2020
** my_lib_file
** File description:
** dir_index.c
*/

#include "file.h"

static bool get_filepath(DIR *directory, unsigned char type)
{
    struct dirent *act = NULL;

    do {
        act = readdir(directory);
        if (!act)
            return false;
    } while (act->d_type != type || act->d_name[0] == '.');
    return true;
}

size_t nb_in_dir(char *dirpath, unsigned char type)
{
    DIR *directory = NULL;
    size_t nb_dirs = 0;
    bool good_type = false;

    if (!dirpath || !is_dir_openable(dirpath))
        return 0;
    directory = opendir(dirpath);
    do {
        good_type = get_filepath(directory, type);
        if (good_type)
            nb_dirs++;
    } while (good_type);
    closedir(directory);
    return nb_dirs;
}
