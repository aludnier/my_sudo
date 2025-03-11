/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hashtable.h
*/

#include <stdbool.h>
#include <sys/types.h>


#ifndef OPT_H
    #define OPT_H
    #define E_OPT 0
    #define S_OPT 1
    #define U_OPT 2
    #define G_OPT 3
#endif

#ifndef SUDO_H
    #define SUDO_H
    #define ERROR_EXIT 84
    #define SUCCESS_EXIT 0
    #define SUCCESS 0
    #define FAIL 1
    #define EXIT -1
    #define STDERR 2
    #define ON 1
    #define OFF 0
    #define PRIVTIME 300

struct sudo_data_s {
    char *command;
    char **arg;
    char *u_opt;
    char *g_opt;
    bool E_opt;
    bool s_opt;
    char **env;
};

bool user_exist(char *usr);
bool error(char *msg, char *extra);
int environment(struct sudo_data_s *data);
void free_data(struct sudo_data_s *data);
bool get_uid(char const *usr, uid_t *uid, gid_t *gid);
bool get_gid(char const *group, gid_t *gid);
char *get_password(void);
bool get_attemp(void);
int execute(struct sudo_data_s *data);
int exit_sudo(struct sudo_data_s *data);
void print_data(struct sudo_data_s *data);
bool verify_access(char *user);
char *get_user(void);
int my_getnb_uid(char *str);

bool have_privilege(void);
void create_privilege(char *user);

#endif /* SUDO_H */
