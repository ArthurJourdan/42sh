/*
** EPITECH PROJECT, 2019
** my
** File description:
** my.h
*/

#ifndef PRINT_H_
#define PRINT_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdbool.h>

#include <errno.h>
#include <string.h>

#define DEFAULT        "\033[00m"
#define BOLD           "\e[1m"
#define DIM            "\e[2m"
#define UNDLN          "\e[4m"

#define SHINE          "\e[5;37m"
#define WHITE_RODE     "\e[9;37m"
#define WHITE_BOLD     "\e[1;37m"

#define BLACK          "\e[30m"
#define RED            "\e[31m"
#define GREEN          "\e[32m"
#define YELLOW         "\e[33m"
#define BLUE           "\e[34m"
#define MAGEN          "\e[35m"
#define CYAN           "\e[36m"

#define LIGHT_RED              "\e[91m"
#define LIGHT_GREEN            "\e[92m"
#define LIGHT_YELLOW           "\e[93m"
#define LIGHT_BLUE             "\e[94m"
#define LIGHT_MAGEN            "\e[95m"
#define LIGHT_CYAN             "\e[96m"

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))


#define USELESS __attribute__((unused))

typedef struct functions {
    char c;
    void (*ptr)();
} functions_t;

void my_dprintf(int const output, char *str, ...);
void my_putchar(int const output, int c);
void my_putstr(int const output, char const *str);
void my_putnbr(int const output, int nb);
void my_puthexa(int const output, unsigned int nb);
void my_puthexa_c(int const output, unsigned int nb);
void my_putoctal(int const output, unsigned int nb);
void my_putbin(int const output, unsigned int nb);
void put_non_p(int const output, char *str);
void my_putdouble_arr(int const output, char **arr);
void my_putdouble_arr_newline(int const output, char **arr);
void my_putdouble_arr_one_newline(int const output, char **arr);

#endif /*PRINT_H_*/
