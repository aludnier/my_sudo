/*
** EPITECH PROJECT, 2025
** my_suod
** File description:
** verify user is part of sudo group
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "my_sudo.h"
#include "lib.h"

static int is_in_group(char *user, char **group_user)
{
    for (int i = 0; i < len_word_arr(group_user); i++){
        if (!my_strcmp(group_user[i], user))
            return 1;
    }
    return 0;
}

static char *get_group_from_line(char *line)
{
    char *tmp = strtok(line, ":");
    char *group_line = malloc(sizeof(char) *my_strlen(tmp) + 1);

    group_line[0] = '%';
    for (int i = 0; i < my_strlen(tmp); i++)
        group_line[1 + i] = tmp[i];
    group_line[my_strlen(group_line)] = '\0';
    return group_line;
}

static bool verify_group_user(char *line, char *user, char *group)
{
    char *list_user = NULL;
    char **group_user = NULL;
    char *group_line = get_group_from_line(line);

    if (!my_strcmp(group_line, "%sudo") || !my_strcmp(group_line, group)){
        for (int i = 0; i < 3; i++)
            list_user = strtok(NULL, ":");
        group_user = my_str_to_word_arr(list_user, ',');
        if (is_in_group(user, group_user)){
            free(group_line);
            return SUCCESS;
        }
    }
    free(group_line);
    free_word_arr(group_user);
    return FAIL;
}

bool verify_group(char *user, char *group)
{
    FILE *file = fopen("/etc/group", "r");
    char *line = NULL;
    size_t len = 0;

    if (!file){
        my_dprintf(2, "fail opening group file\n");
        return FAIL;
    }
    while (getline(&line, &len, file) != -1){
        if (verify_group_user(line, user, group) == SUCCESS){
            fclose(file);
            free(line);
            return SUCCESS;
        }
    }
    fclose(file);
    free(line);
    my_dprintf(1, user);
    my_dprintf(1, " is not in the sudoers file.\n");
    return FAIL;
}

static bool verify_user(char *user, char *line_user)
{
    if (line_user[0] == '#'){
        for (int i = 0; i < my_strlen(line_user); i++)
            line_user[i] = line_user[i + 1];
        if (my_getnb_uid(line_user) == (int)getuid())
            return SUCCESS;
        return FAIL;
    }
    if (!my_strcmp(user, line_user))
        return SUCCESS;
    return FAIL;
}

bool verify_access(char *user)
{
    FILE *sudoers = fopen("/etc/sudoers", "r");
    char *line = NULL;
    size_t len = 0;
    bool status = FAIL;

    if (!sudoers){
        my_dprintf(2, "cannot open sudoer.");
        return NULL;
    }
    while (getline(&line, &len, sudoers) != -1){
        if (status == SUCCESS)
            return SUCCESS;
        if (strstr(line, "ALL=(ALL) ALL") && line[0] == '%')
            status = verify_group(user, strtok(line, " "));
        if (strstr(line, "ALL=(ALL) ALL") && line[0] != '%')
            status = verify_user(line, strtok(line, " "));
    }
    return FAIL;
}
