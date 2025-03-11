/*
** EPITECH PROJECT, 2025
** my_sudo
** File description:
** get user
*/

#include "lib.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int my_getnb_uid(char *str)
{
    int nb = 0;

    for (int i = 0; str[i]; i++){
        nb += str[i] - '0';
        if (str[i + 1]){
            nb *= 10;
            continue;
        }
        break;
    }
    return nb;
}

char *get_user(void)
{
    FILE *passwd = fopen("/etc/passwd", "r");
    char *line = NULL;
    size_t n = 0;
    char *user = NULL;

    if (!passwd){
        my_dprintf(2, "cannot open passwd\n");
        return NULL;
    }
    while (getline(&line, &n, passwd) != -1){
        user = strtok(line, ":");
        strtok(NULL, ":");
        if (my_getnb_uid(strtok(NULL, ":")) == (int)getuid())
            break;
    }
    fclose(passwd);
    return user;
}
