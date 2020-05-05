/*
** EPITECH PROJECT, 2020
** PSU_minishell2
** File description:
** command_exists.c
*/

#include "print.h"
#include "file.h"

#include "minishell.h"
#include "parsing_command_line.h"

static bool is_good_command(char * const command, struct dirent *act_dirent)
{
    if (act_dirent && my_strcmp(command, act_dirent->d_name)) {
        return true;
    }
    return false;
}

static bool is_good_folder(char * const command, DIR *actual_dir)
{
    struct dirent *act_dirent = NULL;

    act_dirent = readdir(actual_dir);
    while (act_dirent) {
        if (is_good_command(command, act_dirent))
            return true;
        act_dirent = readdir(actual_dir);
    }
    return false;
}

char *command_match(char **path_arr, char * const is_command)
{
    DIR *actual_dir = NULL;

    for (size_t which_path = 0; path_arr[which_path]; which_path++) {
        actual_dir = opendir(path_arr[which_path]);
        if (!actual_dir)
            continue;
        if (is_good_folder(is_command, actual_dir)) {
            return my_strcat_path(path_arr[which_path], is_command);
        }
    }
    return NULL;
}