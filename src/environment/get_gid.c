/*
** EPITECH PROJECT, 2025
** my_sudo
** File description:
** get user attemp
*/

#include "my_sudo.h"
#include "lib.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

static bool finded_uid(gid_t *gid)
{
    char *idk = strtok(NULL, ":");
    char *gid_temp = strtok(NULL, ":");

    if (idk == NULL)
        return EXIT_FAILURE;
    *gid = (gid_t) strtol(gid_temp, NULL, 10);
    return 0;
}

bool get_gid(char const *group, gid_t *gid)
{
    FILE *file;
    char line[201];
    char *temp_usr = NULL;

    file = fopen("/etc/group", "r");
    if (file == NULL)
        return error("[ERROR] - opening file \"/etc/group\"\n", NULL);
    while (fgets(line, 200, file) != NULL) {
        temp_usr = strtok(line, ":");
        if (temp_usr != NULL && my_strcmp(temp_usr, group) == 0) {
            finded_uid(gid);
            fclose(file);
            return SUCCESS;
        }
    }
    fclose(file);
    return FAIL;
}
