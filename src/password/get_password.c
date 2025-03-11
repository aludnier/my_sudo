/*
** EPITECH PROJECT, 2025
** my_sudo
** File description:
** get password from user
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "lib.h"
#include "my_sudo.h"

static int check_user(char *line)
{
    char *user = strtok(line, ":");

    if (!strcmp(user, get_user())){
        return 1;
    }
    return 0;
}

char *get_password(void)
{
    FILE *file = fopen("/etc/shadow", "r");
    char *line = NULL;
    size_t n = 0;
    char *pass = NULL;

    if (!file){
        my_dprintf(2, "cannot open shadow\n");
        return NULL;
    }
    while (getline(&line, &n, file) != -1){
        if (check_user(my_strcpy(line))){
            break;
        }
    }
    strtok(line, ":");
    pass = strtok(NULL, ":");
    fclose(file);
    return pass;
}
