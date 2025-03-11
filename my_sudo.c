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

static const char option[5][3] = {"-E", "-s", "-u", "-g"};

void free_data(struct sudo_data_s *data)
{
    if (data->command != NULL)
        free(data->command);
    if (data->u_opt != NULL)
        free(data->u_opt);
    if (data->g_opt != NULL)
        free(data->g_opt);
    if (data->arg != NULL) {
        for (int i = 0; data->arg[i] != NULL; i++)
            free(data->arg[i]);
        free(data);
    }
}

static void u_opt(struct sudo_data_s *data, char *usr)
{
    if (user_exist(usr)) {
        free_data(data);
        free(usr);
        exit(84);
    }
    data->u_opt = usr;
}

static int add_sudo_data_ouput(int const opt, char const **av,
    int numberMesh, struct sudo_data_s *data)
{
    char *ouput = NULL;

    if (av[numberMesh + 1] == NULL) {
        my_dprintf(2,
        "[ERROR] - This option requires one more argument.\n");
        return ERROR_EXIT;
    }
    ouput = my_strcpy(av[numberMesh + 1]);
    if (ouput == NULL) {
        my_dprintf(2,
        "[ERROR] - Oops, it seems that I can't put the memory\n");
        return ERROR_EXIT;
    }
    if (opt == U_OPT)
        u_opt(data, ouput);
    else
        data->g_opt = ouput;
    return (numberMesh + 1);
}

static int add_sudo_data(int const opt, char const **av,
    int numberMesh, struct sudo_data_s *data)
{
    switch (opt) {
        case E_OPT:
            data->E_opt = ON;
            return numberMesh;
        case S_OPT:
            data->s_opt = ON;
            return numberMesh;
    }
    return add_sudo_data_ouput(opt, av, numberMesh, data);
}

static int check_option(char const **av,
    int numberMesh, struct sudo_data_s *data)
{
    for (int i = 0; i != 4; i++) {
        if (my_strcmp(av[numberMesh], option[i]) == 0)
            return add_sudo_data(i, av, numberMesh, data);
    }
    my_dprintf(2, "[ERROR] - The opt used does not exist\n");
    return EXIT;
}

static int get_args(char const **av, int numberMesh, struct sudo_data_s *data)
{
    if (av[numberMesh] == NULL) {
        if (have_privilege() == SUCCESS)
            return environment(data);
        if (get_attemp() == FAIL)
            return ERROR_EXIT;
        create_privilege(get_user());
        return environment(data);
    }
    if (add_str(av[numberMesh], &data->arg)) {
        free_data(data);
        return EXIT_FAILURE;
    }
    return get_args(av, numberMesh + 1, data);
}

static int parsing(int const ac, char const **av,
    int numberMesh, struct sudo_data_s *data)
{
    if (numberMesh >= ac) {
        if (get_attemp() == FAIL)
            return ERROR_EXIT;
        return environment(data);
    }
    if (av[numberMesh][0] == '-') {
        numberMesh = check_option(av, numberMesh, data);
        if (numberMesh == EXIT) {
            return ERROR_EXIT;
        }
    } else {
        data->command = my_strcpy(av[numberMesh]);
        if (data->command == NULL)
            return ERROR_EXIT;
        return get_args(av, numberMesh, data);
    }
    return parsing(ac, av, numberMesh + 1, data);
}

static int display_help(void)
{
    my_dprintf(1, "usage: ./my_sudo -h\n");
    my_dprintf(1, "usage: ./my_sudo [-ugEs] [command [args ...]]\n");
    return SUCCESS_EXIT;
}

static int my_sudo(int const ac, char const **av, char **env)
{
    struct sudo_data_s data = {NULL, NULL, NULL, NULL, OFF, OFF, env};

    if (ac == 2 && my_strcmp(av[1], "-h") == 0){
        return display_help();
    }
    if (ac <= 1) {
        my_dprintf(STDERR,
        "[ERRROR] - at least one argument is required!\n -> try \"-h\"\n");
        return ERROR_EXIT;
    }
    return parsing(ac, av, 1, &data);
}

int main(int const argc, char const **argv, char **env)
{
    return my_sudo(argc, argv, env);
}
