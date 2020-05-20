/*
** EPITECH PROJECT, 2020
** 42SH
** File description:
** Double input redirection
*/

#include "my.h"
#include "file.h"

#include "minishell.h"
#include "parsing_command_line.h"

void create_fd_redirect(char *line, char **fp)
{
    int fd = -1;
    char c = '\n';

    fd = open(fp[0], O_CREAT | O_APPEND | O_RDWR, \
              S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    while (1) {
        putchar('?');
        line = command_read();
        line = rm_char_in_str(line, '\n');
        if (my_strcmp(fp[0], line) == true)
            break;
        for (int i= 0; line[i] != '\0'; i++)
            write(fd, &line[i], 1);
        write(fd, &c, 1);
    }
}
