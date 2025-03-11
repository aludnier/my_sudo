/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** display one by one, the characters of a string
*/

#include <unistd.h>
#include "lib.h"

int my_dprintf(int const nb, char const *str)
{
    int count = my_strlen(str);
    int ret = 0;

    ret = write(nb, str, count);
    return ret;
}
