/*
** EPITECH PROJECT, 2019
** my
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#define _GNU_SOURCE

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdbool.h>

#include <errno.h>
#include <string.h>

#include <signal.h>

#include <time.h>

#include <sys/types.h>
#include <sys/wait.h>


#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))
#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)

#undef EXIT_FAILURE
#define EXIT_FAILURE (84)

// ATTRIBUTES
#define N_U __attribute__((unused))
#define UNUSED __attribute__((unused))
#define PURE __attribute__((pure))
#define CONSTRUCTOR __attribute__((constructor))
#define DESTRUCTOR __attribute__((destructor))
#define INLINE __attribute__((always_inline))
#define NO_INLINE __attribute__((noinline))
#define CONST __attribute__((const))
#define MALLOC __attribute__((malloc))
#define NO_RETURN __attribute__((noreturn))
// !ATTRIBUTES

typedef struct {
    int x;
    int y;
} vector_t;

// CHECK

// LEN
size_t my_strlen(char const *str);
size_t my_arrlen(char **arr);
size_t my_triplearrlen(char **arr[]);
size_t my_len_tot(char const *str);
size_t my_int_arr_len(int *arr);
size_t my_strlen_until_word(char * const str, char * const word);
// !LEN

// IS IT THAT
bool my_char_is_alpha_num(char const c, bool alpha, bool num, bool up);
bool my_str_is_alphanum(char const *str);
bool my_str_is_alpha(char const *str);
bool my_str_is_upper(char const *str);
bool my_str_is_num(char const *str);
bool my_str_is_float(char const *str);
bool my_char_is_nothing(char const c, bool alpha, bool num, bool up);
bool my_str_is_nothing(char const *str);
bool my_quotation_is_nothing(char const *str);

bool my_str_is_chars(char * const str, size_t ac, ...);

bool my_str_has_char(char * const str, char c);
bool my_str_has_chars(char * const str, size_t ac, ...);
// !IS IT THAT

bool error_msg(int ac, char **av);

// CMP
bool my_strcmp(char const *str_1, char const *str_2);
bool my_str_n_cmp(char const *str_1, char const *str_2, int len);

ssize_t biggest_in_double_arr(char **src);
// CMP
// !CHECK


// NUM
int my_getnbr(char *str);
float my_getfloat(char *str);
int my_getdigit(char nb);
char *my_reg_nbr(int nb);

bool invert_bool(bool my_bool);
int invert_int(int nb);
// !NUM


// MODIF

// CONCATENATE
char *my_strcat(char *str1, char *str2, bool free_1, bool free_2);
char *my_strcat_path(char const *str1, char const *str2);
char **my_arrcat(char **arr1, char **arr2, bool free);
char ***my_triple_arrcat(char ***arr1, char ***arr2);
char *my_strcat_tot(size_t ac, ...);
char **my_two_str_to_arr(char *str1, char *str2, bool free);
// !CONCATENATE


// CPY
char *my_strcpy(char *str);
char *my_str_n_cpy(char *str, size_t size);
char *my_str_cpy_until_char(char *str, char c);
char *my_str_cpy_until_str(char *str, char *cmp);
char *my_str_cpy_quotation(char *str, bool double_q, bool simple, bool magic);

char **double_char_arr_cpy(char **src, bool free);
void double_char_arr_dup(char **src, char **new);

char *get_nth_word_in_str(char * const str, size_t n);
// !CPY

// MANIPULATE ARR
char **add_str_to_arr(char **arr, char *str, bool free_arr, bool free_str);
char **remove_str_to_arr(char **arr, size_t index_str, bool to_free);
// !MANIPULATE ARR

// CHANGE TYPE
char *my_word_arr_to_str(char **arr);
char **my_str_to_word_arr(char *str);

char **my_sep_parser(char * const str, char * const sep);
char **my_n_sep_parser(char * const str, char **seps);

char **arr_from_hard_quote(size_t ac, ...);
// !CHANGE TYPE

// CHANGE ORDER
void sort_arr_alphabetically(char **arr);
char **reverse_double_arr(char **src, bool to_free);
void reverse_str(char *str);
// !CHANGE ORDER

// REPLACE
void replace_char_in_str(char *str, char const old, char new);
void replace_char_in_arr(char **arr, char const old, char new);
// !REPLACE

// MEMSET
void my_memset_str(char *array, int c, size_t len);
void my_memset_char_arr(char **arr, char *ptr, size_t len);
// !MEMSET

// !MODIF

// FREE
void free_double_char_arr(char **arr);
void free_triple_char_arr(char ***arr);
char *free_char_to_null(char *str);
// !FREE

#endif /*MY_H_*/
