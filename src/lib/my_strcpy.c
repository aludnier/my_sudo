/*
** EPITECH PROJECT, 2025
** B-CPE-110-PAR-1-1-bssecured-jean-francois2.villacorta-barbat (Workspace)
** File description:
** my_strcpy
*/

#include <stddef.h>
#include <stdlib.h>
#include "lib.h"

char *my_strcpy(char const *str)
{
    char *cpy = NULL;
    int len = 0;

    if (str == NULL)
        return NULL;
    len = my_strlen(str);
    cpy = malloc(sizeof(char) * (len + 1));
    if (cpy == NULL)
        return NULL;
    for (int i = 0; i != len + 1; i++)
        cpy[i] = str[i];
    return cpy;
}
