/*
** EPITECH PROJECT, 2025
** my_sudo
** File description:
** create privelege files
*/

#include "lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <crypt.h>
#include <unistd.h>
#include <sys/stat.h>

void create_privilege(char *user)
{
    FILE *privilege = fopen("priv.txt", "w");

    if (!privilege)
        my_dprintf(2, "fail open priv.txt\n");
    user = crypt(user, "crypt");
    fprintf(privilege, "%s\n", user);
    fclose(privilege);
    chmod("priv.txt", 0400);
}
