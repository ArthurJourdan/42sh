/*
** EPITECH PROJECT, 2020
** lib_file
** File description:
** get_entire_file.c
*/

#include "file.h"
#include "my.h"

char *get_entire_file(char const *filepath)
{
    FILE *fd = NULL;
    char *buff = NULL;
    size_t zero = 0;
    int ret_get_l = 0;
    char *entire_file = NULL;

    if (!is_file_openable(filepath))
        return NULL;
    fd = fopen(filepath, "r");
    ret_get_l = getline(&buff, &zero, fd);
    while (ret_get_l != -1) {
        entire_file = my_strcat_free(entire_file, buff);
        ret_get_l = getline(&buff, &zero, fd);
    }
    free(buff);
    fclose(fd);
    return entire_file;
}

char **get_entire_file_double_arr(char const *filepath)
{
    FILE *fd = fopen(filepath, "r");
    char *buff = NULL;
    size_t zero = 0;
    int ret_get_l = 1;
    char **entire_file = NULL;
    size_t len = file_len(filepath);

    if (len <= 0 || !fd)
        return NULL;
    entire_file = malloc(sizeof(char *) * (len + 1));
    entire_file[len] = NULL;
    for (size_t a = 0; a < len; a++) {
        entire_file[a] = NULL;
        ret_get_l = getline(&entire_file[a], &zero, fd);
        if (ret_get_l == -1 || !entire_file[a])
            break;
        if (check_comments(entire_file[a]))
            free(entire_file[a--]);
    }
    fclose(fd);
    return entire_file;
}