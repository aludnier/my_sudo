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
#include <string.h>
#include <errno.h>
#include <unistd.h>

static int set_uid_gid(uid_t uid, gid_t gid, struct sudo_data_s *data)
{
    if (setgid(gid) == -1) {
        my_dprintf(STDERR, "[ERROR] - not posible to change to the group\n");
        return FAIL;
    }
    if (setuid(uid) == -1) {
        my_dprintf(STDERR, "[ERROR] - not posible to change to the user\n");
        return FAIL;
    }
    return execute(data);
}

static bool user_opt(struct sudo_data_s *data, uid_t *uid, gid_t *gid)
{
    if (get_uid(data->u_opt, uid, gid)) {
        free_data(data);
        return FAIL;
    }
    return SUCCESS;
}

static bool group_opt(struct sudo_data_s *data, gid_t *gid)
{
    if (get_gid(data->g_opt, gid)) {
        free_data(data);
        return FAIL;
    }
    return SUCCESS;
}

int environment(struct sudo_data_s *data)
{
    uid_t uid = 0;
    gid_t gid = 0;

    if (data->u_opt != NULL)
        if (user_opt(data, &uid, &gid))
            return EXIT_FAILURE;
    if (data->g_opt != NULL)
        if (group_opt(data, &gid))
            return EXIT_FAILURE;
    return set_uid_gid(uid, gid, data);
}
