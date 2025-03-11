/*
** EPITECH PROJECT, 2025
** my_sudo
** File description:
** verify privelege files
*/

#include "lib.h"
#include "my_sudo.h"
#include <crypt.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

static bool last_update(void)
{
    time_t timestamp = time(NULL);
    int fd = open("priv.txt", O_RDONLY);
    struct stat stat_buff;
    bool status = FAIL;

    if (fstat(fd, &stat_buff) == -1){
        printf("failed\n");
        return FAIL;
    }
    if (timestamp - stat_buff.st_mtime < PRIVTIME)
        status = SUCCESS;
    close(fd);
    return status;
}

bool have_privilege(void)
{
    FILE *priv = fopen("priv.txt", "r");
    char *line = NULL;
    size_t n = 0;

    if (!priv){
        return FAIL;
    }
    if (getline(&line, &n, priv) == -1)
        return FAIL;
    line[my_strlen(line) - 1] = '\0';
    if (!my_strcmp(line, crypt(get_user(), "crypt")) &&
        last_update() == SUCCESS)
        return SUCCESS;
    return FAIL;
}
