/*
** EPITECH PROJECT, 2020
** my_lib_file
** File description:
** file_len.c
*/

#include "file.h"
#include "my.h"
#include "print.h"

static size_t const CHECK = 100;

bool check_first_line(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buff[CHECK];
    ssize_t ret_read = 0;

    if (fd == -1)
        return false;
    ret_read = read(fd, buff, CHECK);
    if (ret_read == -1)
        return false;
    if (ret_read < CHECK)
        return true;
    for (size_t a = 0; a < ret_read; a++) {
        if (buff[a] == '\n') {
            return true;
        }
    }
    close(fd);
    return false;
}

size_t file_len(char const *filepath)
{
    FILE *fd = fopen(filepath, "r");
    char *buff = NULL;
    size_t zero = 0;
    size_t len = 0;
    ssize_t ret_get_l = 0;

    if (!fd || !check_first_line(filepath))
        return 0;
    for (; ret_get_l != -1; len++) {
        ret_get_l = getline(&buff, &zero, fd);
        if (check_comments(buff))
            len--;
    }
    if (buff)
        free(buff);
    if (fd)
        fclose(fd);
    if (zero <= 0 || len == 0)
        return 0;
    return --len;
}