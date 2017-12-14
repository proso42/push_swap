# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: proso <proso@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/27 13:41:20 by proso             #+#    #+#              #
#    Updated: 2017/12/14 03:56:54 by proso            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

NAME2 = push_swap

SRC = check_argv.c \
	  check_commands.c \
	  checker.c \
	  commands.c \
	  commands2.c \
	  db_list_last.c \
	  db_push_back.c \
	  db_push_front.c \
	  db_remove_first.c \
	  print_db_list.c \
	  print_error.c

SRC2 = push_swap.c

CC = gcc

FLAGS = -Wall -Werror -Wextra -fsanitize=address

INCLUDE = Includes/push_swap.h

LIB = Libft/libft.a

OBJ = $(addprefix $(DIR_OBJ), $(SRC:.c=.o))

OBJ2 = $(addprefix $(DIR_OBJ), $(SRC2:.c=.o))

DIR_OBJ = ./OBJ/

DIR_OBJ2 = ./OBJ/

DIR_SRC = ./Sources/

all: $(NAME)

$(DIR_OBJ)%.o	:	$(DIR_SRC)%.c $(INCLUDE)
	@$(CC) $(FLAGS) -I./$(INCLUDE) -o $@ -c $<
	@Progress_bar/p_bar_push_swap $<
	@sleep 0.05

$(DIR_OBJ2)%.o	:	$(DIR_SRC)%.c $(INCLUDE)
	@$(CC) $(FLAGS) -I./$(INCLUDE) -o $@ -c $<
	@Progress_bar/p_bar_push_swap $<
	@sleep 0.05
clr:
	@clear

make_lib:
	@make -C Libft/
	@clear
	@echo "\x1b[33m\x1b[1mMaking executable... ⏳\x1b[0m"
	@sleep 1

$(NAME): clr make_lib $(OBJ) $(OBJ2) $(INCLUDE)
	@$(CC) $(FLAGS) -o $(NAME) $(LIB) $(OBJ)
	@sleep 1
	@clear
	@echo "\x1b[32m\x1b[1mChecker sucessfully created ✓\x1b[0m"
	@$(CC) $(FLAGS) -o $(NAME2) $(LIB) OBJ/check_argv.o OBJ/db* OBJ/print* OBJ/commands* $(OBJ2)
	@sleep 1
	@clear
	@echo "\x1b[32m\x1b[1mPush_swap sucessfully created ✓\x1b[0m"

clean:
	@make clean -C Libft/
	@rm -f $(OBJ)
	@echo "\x1b[31m\x1b[1mAll objects deleted ✖\x1b[0m"

fclean: clean
	@make fclean -C Libft/
	@rm -f $(NAME)
	@echo "\x1b[31m\x1b[1mExecutable deleted ✖\x1b[0m"

local_clean:
	@rm -f $(OBJ) $(OBJ2)
	@echo "\x1b[31m\x1b[1mAll objects deleted ✖\x1b[0m"

local_fclean: local_clean
	@rm -f $(NAME) $(NAME2)
	@echo "\x1b[31m\x1b[1mExecutable deleted ✖\x1b[0m"

local_re: local_fclean all

re: fclean all
