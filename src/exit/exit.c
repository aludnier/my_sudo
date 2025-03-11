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

static int exit_e_opt(struct sudo_data_s *data)
{
    free_data(data);
    return EXIT_SUCCESS;
}

static int exit_s_opt(struct sudo_data_s *data)
{
    free_data(data);
    return EXIT_SUCCESS;
}

int exit_sudo(struct sudo_data_s *data)
{
    if (data->E_opt)
        return exit_e_opt(data);
    if (data->s_opt)
        return exit_s_opt(data);
    free_data(data);
    return EXIT_SUCCESS;
}
