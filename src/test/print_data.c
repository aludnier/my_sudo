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

void print_command(struct sudo_data_s *data)
{
    if (data->command == NULL)
        printf("command = NULL\n");
    else
        printf("command = %s\n", data->command);
    if (data->arg != NULL) {
        for (int i = 0; data->arg[i] != NULL; i++) {
            printf("%s\n", data->arg[i]);
        }
    }
}

void print_data(struct sudo_data_s *data)
{
    if (data->u_opt == NULL)
        printf("u_opt = NULL\n");
    else
        printf("u_opt = %s\n", data->u_opt);
    if (data->g_opt == NULL)
        printf("g_opt = NULL\n");
    else
        printf("g_opt = %s\n", data->g_opt);
    if (data->E_opt == OFF)
        printf("e_opt = OFF\n");
    else
        printf("E_opt = ON\n");
    if (data->s_opt == OFF)
        printf("s_opt = OFF\n");
    else
        printf("s_opt = ON\n");
    print_command(data);
}
