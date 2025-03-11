/*
** EPITECH PROJECT, 2024
** setting_up
** File description:
** setting_up
*/

#include <stdlib.h>

int my_strcmp(const char *str1, const char *str2)
{
    char c1 = '\0';
    char c2 = '\0';
    int x = 0;

    while (str1[x] != '\0' && str2[x] != '\0') {
        c1 = str1[x];
        c2 = str2[x];
        if (c1 >= 'A' && c1 <= 'Z')
            c1 = c1 + 'a' - 'A';
        if (c2 >= 'A' && c2 <= 'Z')
            c2 = c2 + 'a' - 'A';
        if (c1 != c2) {
            return (unsigned char)c1 - (unsigned char)c2;
        }
        x++;
    }
    return (unsigned char)str1[x] - (unsigned char)str2[x];
}
