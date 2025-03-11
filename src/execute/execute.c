/*
** EPITECH PROJECT, 2025
** B-CPE-110-PAR-1-1-bssecured-jean-francois2.villacorta-barbat (Workspace)
** File description:
** my_sudo
*/

#include "lib.h"
#include "my_sudo.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int execute_e(struct sudo_data_s *data)
{
    char *path = my_str_cmb("/bin/", data->command);

    if (path == NULL) {
        free_data(data);
        return EXIT_FAILURE;
    }
    if (execve(path, data->arg, data->env) == -1) {
        my_dprintf(STDERR, "[ERROR] - executing the comand\n");
        return EXIT_FAILURE;
    }
    return SUCCESS;
}

static int execute_default(struct sudo_data_s *data)
{
    if (execvp(data->command, data->arg) == -1) {
        my_dprintf(STDERR, "[ERROR] - executing the comand\n");
        return EXIT_FAILURE;
    }
    return SUCCESS;
}

int execute(struct sudo_data_s *data)
{
    if (data->command != NULL) {
        if (data->E_opt == ON)
            return execute_e(data);
        else
            return execute_default(data);
    }
    return exit_sudo(data);
}
