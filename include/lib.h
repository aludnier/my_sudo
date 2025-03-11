/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hashtable.h
*/

#include <stdbool.h>
#include <stdio.h>

#ifndef LIB_H
    #define LIB_H
    #define ERROR_EXIT 84
    #define SUCCESS 0
    #define FAIL 1

int my_dprintf(int const nb, char const *str);
int my_strcmp(const char *str1, const char *str2);
int my_strlen(char const *str);
char *my_strcpy(char const *str);
bool add_str(const char *str, char ***arr);
char *my_str_cmb(const char *str1, const char *str2);
char **my_str_to_word_arr(const char *str, char delim);
int len_word_arr(char **arr);
void free_word_arr(char **arr);

#endif /* LIB */
