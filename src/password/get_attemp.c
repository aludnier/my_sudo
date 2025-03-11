/*
** EPITECH PROJECT, 2025
** my_sudo
** File description:
** get user attemp
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <crypt.h>
#include "lib.h"
#include "my_sudo.h"
#include <termios.h>

static bool verify_sudoperm(char *user)
{
    if (verify_access(user) == FAIL)
        return FAIL;
    return SUCCESS;
}

static void print_fail_attemp(int nb_attemp)
{
    if (nb_attemp < 2)
        printf("\nSorry, try again.\n");
    else
        printf("\nmy_sudo: 3 incorrect password attempts\n");
}

static void set_echo(int status)
{
    struct termios t;

    if (tcgetattr(STDIN_FILENO, &t) == -1)
        return;
    if (status == ON){
        t.c_lflag |= ECHO;
    }
    if (status == OFF){
        t.c_lflag &= ~((tcflag_t) ECHO);
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

static bool ask_password(char *user, char *password)
{
    size_t len = 0;
    char *attemp = NULL;

    set_echo(OFF);
    for (int nb_attemp = 0; nb_attemp < 3; nb_attemp++){
        printf("[my_sudo] password for %s: ", user);
        getline(&attemp, &len, stdin);
        attemp[my_strlen(attemp) - 1] = '\0';
        if (!my_strcmp(crypt(attemp, password), password)){
            free(attemp);
            set_echo(ON);
            printf("\n");
            return verify_sudoperm(user);
        }
        sleep(2.5);
        print_fail_attemp(nb_attemp);
    }
    set_echo(ON);
    free(attemp);
    return FAIL;
}

bool get_attemp(void)
{
    char *user = get_user();
    char *password = get_password();

    if (!password)
        return FAIL;
    if (!my_strcmp(user, "root"))
        return SUCCESS;
    return ask_password(user, password);
}
