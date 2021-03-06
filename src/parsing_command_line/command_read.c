/*
** EPITECH PROJECT, 2020
** PSU_minishell2
** File description:
** command_interpreter.c
*/

#include "my.h"
#include "file.h"
#include "print.h"

#include "minishell.h"
#include "parsing_command_line.h"

static char *get_one_line(void)
{
    char *line = NULL;
    size_t zero = 0;

    if (getline(&line, &zero, stdin) == -1)
        return NULL;
    return line;
}

static char *fill_quote(char *line)
{
    char *tmp = NULL;
    char *new_line = NULL;

    tmp = get_one_line();
    if (!tmp)
        return NULL;
    new_line = my_strcat(line, tmp, true, true);
    return new_line;
}

char *command_read(void)
{
    char *line = NULL;

    line = get_one_line();
    if (!line) {
        if (isatty(STDIN_FILENO) == 1)
            my_dprintf(1, "exit\n");
        return my_strcpy("exit\n");
    }
    if (BONUS) {
        while (line && !are_quotes_filled(line))
            line = fill_quote(line);
    }
    return line;
}

static void print_color_folder(char *pwd)
{
    char *color = my_strcpy("\e[90m");

    color[3] = ((getpid()) % 8) + 48;
    my_dprintf(STDOUT_FILENO, "%s", color);
    my_dprintf(STDOUT_FILENO, "%s", pwd);
    my_dprintf(STDOUT_FILENO, "> %s", DEFAULT);
    free(color);
}

void print_prompt(void)
{
    char *pwd = NULL;

    if (isatty(STDIN_FILENO) != 1)
        return;
    pwd = getcwd(pwd, 0);
    if (pwd) {
        print_color_folder(pwd);
    } else
        my_dprintf(STDOUT_FILENO, "%s~> %s", YELLOW, DEFAULT);
}