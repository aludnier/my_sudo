/*
** EPITECH PROJECT, 2025
** my_sudo
** File description:
** get user attemp
*/

#include "my_sudo.h"
#include "lib.h"
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>

bool error(char *msg, char *extra)
{
    dprintf(STDERR, msg, extra);
    return FAIL;
}

bool user_exist(char *usr)
{
    FILE *file;
    char line[201];
    char *temp_usr = NULL;

    file = fopen("/etc/passwd", "r");
    if (file == NULL)
        return error("[ERROR] - opening file \"/etc/passwd\"\n", NULL);
    while (fgets(line, 200, file) != NULL) {
        temp_usr = strtok(line, ":");
        if (temp_usr != NULL && my_strcmp(temp_usr, usr) == 0) {
            fclose(file);
            return SUCCESS;
        }
    }
    fclose(file);
    return error("my_sudo: unknow user %s\n", usr);
}
