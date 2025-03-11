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

static bool finded_uid(uid_t *uid, gid_t *gid)
{
    char *idk = strtok(NULL, ":");
    char *uid_temp = strtok(NULL, ":");
    char *gid_temp = strtok(NULL, ":");

    if (idk == NULL)
        return EXIT_FAILURE;
    *uid = (uid_t) strtol(uid_temp, NULL, 10);
    *gid = (gid_t) strtol(gid_temp, NULL, 10);
    return 0;
}

bool get_uid(char const *usr, uid_t *uid, gid_t *gid)
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
            finded_uid(uid, gid);
            fclose(file);
            return SUCCESS;
        }
    }
    fclose(file);
    return FAIL;
}
