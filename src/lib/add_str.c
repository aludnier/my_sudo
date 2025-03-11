/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** display one by one, the characters of a string
*/

#include <stdlib.h>
#include "lib.h"

static int count_arr(char **arr)
{
    int len = 0;

    if (arr == NULL)
        return 0;
    while (arr[len] != NULL)
        len++;
    return len;
}

char **create_arr(const char *str, char **arr)
{
    int len = count_arr(arr);
    int x = 0;
    char **new_arr = malloc(sizeof(char *) * (len + 2));

    while (x != len) {
        new_arr[x] = arr[x];
        x++;
    }
    new_arr[x] = my_strcpy(str);
    if (new_arr[x] == NULL) {
        free(new_arr);
        return NULL;
    }
    new_arr[x + 1] = NULL;
    return new_arr;
}

bool add_str(const char *str, char ***arr)
{
    char **new_arr = NULL;

    if (arr == NULL || arr == NULL)
        return FAIL;
    new_arr = create_arr(str, *arr);
    if (new_arr == NULL)
        return FAIL;
    free(*arr);
    *arr = new_arr;
    return SUCCESS;
}
