/*
** EPITECH PROJECT, 2020
** my_repo
** File description:
** file.h
*/

#ifndef FILE_H_
#define FILE_H_

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>

bool is_file_openable(char const *filepath);
bool is_file_fopenable(char const *filepath);
bool is_dir_openable(char const *filepath);

size_t file_len(char const *filepath);

// DIR
size_t nb_in_dir(char *dirpath, unsigned char type);
char **get_filepaths(char *dirpath, unsigned char type);
// ! DIR

// FIND
ssize_t get_pos_word_in_str(char const  *word, char const *str);
ssize_t get_pos_word_end_in_str(char const *word, char const *str);
ssize_t get_pos_word_in_arr(char const *word, char const **arr);
ssize_t get_index_word_begin_in_arr(char const  *word, char **arr);
// ! FIND

// COUNT
size_t count_words_in_str(char * const str);
size_t count_words(char **arr);
size_t count_occurences_in_str(char * const word, char * const str);
size_t count_occurences(char * const word, char **arr);
size_t count_occurences_n_words_in_str(char **words, char * const str);
size_t count_occurences_n_words(char **words, char **arr);
// ! COUNT

char *get_entire_file(char const *filepath);
char **get_entire_file_double_arr(char const *filepath);


char *rm_trailling_char_in_str(char *str, const char ch);
char **rm_trailling_char_in_double_arr(char **arr, const char ch);
char **rm_char_in_double_arr(char **arr, const char ch);
char *rm_char_in_str(char *str, const char ch);

bool check_comments(char *str);
bool are_quotes_filled(char const * const line);

#endif /*FILE_H_*/
