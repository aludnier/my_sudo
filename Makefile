##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Write a makefile for MiniShell1
##

SRC = my_sudo.c						\
	src/lib/my_dprintf.c 			\
	src/lib/my_strlen.c 			\
	src/lib/my_strcpy.c 			\
	src/lib/my_strcmp.c 			\
	src/lib/add_str.c 				\
	src/lib/my_str_cmb.c 			\
	src/lib/my_str_to_word_array.c	\
	src/password/get_attemp.c		\
	src/password/get_password.c		\
	src/password/verify_sudo_acces.c\
	src/user/user.c					\
	src/user/get_user.c				\
	src/environment/enviroment.c	\
	src/environment/get_uid.c		\
	src/environment/get_gid.c		\
	src/execute/execute.c			\
	src/exit/exit.c					\
	src/test/print_data.c			\
	src/privileges/create_privilege.c\
	src/privileges/verify_privilege.c\

OBJ = $(SRC:.c=.o)

CPPFLAGS = -iquote ./include/

CFLAGS = -Wall -Wextra -g3

LDLIBS = -lcrypt

NAME = my_sudo

MAKE = make

all:	$(NAME)
	sudo chown root $(NAME)
	sudo chmod u+s $(NAME)

clib:
	$(MAKE) -C lib/my/

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME)  $(CFLAGS) $(LDLIBS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f priv.txt

re: fclean all
