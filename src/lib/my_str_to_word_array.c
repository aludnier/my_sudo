/*
** EPITECH PROJECT, 2025
** count_word
** File description:
** str_to_word_aray
*/

#include <stdlib.h>
#include <stdio.h>

static int end_word(const char *str, int index, char delim)
{
    while (str[index] && str[index] != '\n' && str[index] != delim)
        index++;
    return index;
}

static int count_nb_word(const char *str, char delim)
{
    int index = 0;
    int nb_words = 0;

    if (!str)
        return 0;
    while (str[index] && str[index] != '\n'){
        if (str[index] != delim){
            nb_words++;
            index = end_word(str, index, delim);
            continue;
        }
        index++;
    }
    return nb_words;
}

static char *get_word(const char *str, const int begin,
    char delim)
{
    int len = end_word(str, begin, delim) - begin;
    char *word = malloc(sizeof(char) * (len + 1));

    if (!word)
        return NULL;
    for (int i = 0; i < len; i++){
        word[i] = str[begin + i];
    }
    word[len] = '\0';
    return word;
}

char **my_str_to_word_arr(const char *str, char delim)
{
    int len = count_nb_word(str, delim);
    char **arr = malloc(sizeof(char *) * len + 1);
    int index_arr = 0;

    if (!arr)
        return NULL;
    for (int i = 0; str[i] != '\0' && index_arr < len; i++){
        if (str[i] != delim){
            arr[index_arr] = get_word(str, i, delim);
            index_arr++;
            i = end_word(str, i, delim);
        }
    }
    arr[len] = NULL;
    return arr;
}

int len_word_arr(char **arr)
{
    int nb_word = 0;

    while (arr[nb_word] != NULL){
        nb_word++;
    }
    return nb_word;
}

void free_word_arr(char **arr)
{
    if (!arr)
        return;
    for (int i = 0; i < len_word_arr(arr); i++)
        free(arr[i]);
    free(arr);
}
