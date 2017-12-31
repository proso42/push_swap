# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: proso <proso@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/27 13:41:20 by proso             #+#    #+#              #
#    Updated: 2017/12/24 00:37:16 by alexandra        ###   ########.fr        #
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
	  db_list_size.c \
	  db_push_back.c \
	  db_push_front.c \
	  db_remove_first.c \
		find_min_max.c \
	  gen_tab_value.c \
	  get_median.c \
	  ligth_sort.c \
	  median_sort.c \
		opti.c \
	  print_db_list.c \
	  print_error.c \
	  push_min.c \
	  quick_sort.c \
	  re_push_numbers.c \
	  sort_list.c

SRC2 = check_argv.c \
	   commands.c \
 	   commands2.c \
 	   db_list_last.c \
	   db_list_size.c \
 	   db_push_back.c \
 	   db_push_front.c \
 	   db_remove_first.c \
		 find_min_max.c \
	   gen_tab_value.c \
	   get_median.c \
	   ligth_sort.c \
	   median_sort.c \
		 opti.c \
 	   print_db_list.c \
 	   print_error.c \
	   push_min.c \
	   push_swap.c \
	   quick_sort.c \
	   re_push_numbers.c \
	   sort_list.c

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
	@$(CC) $(FLAGS) -o $(NAME2) $(LIB) $(OBJ2)
	@sleep 1
	@clear
	@echo "\x1b[32m\x1b[1mPush_swap sucessfully created ✓\x1b[0m"

clean:
	@make clean -C Libft/
	@rm -f $(OBJ) $(OBJ2)
	@echo "\x1b[31m\x1b[1mAll objects deleted ✖\x1b[0m"

fclean: clean
	@make fclean -C Libft/
	@rm -f $(NAME) $(NAME2)
	@echo "\x1b[31m\x1b[1mExecutable deleted ✖\x1b[0m"

local_clean:
	@rm -f $(OBJ) $(OBJ2)
	@echo "\x1b[31m\x1b[1mAll objects deleted ✖\x1b[0m"

local_fclean: local_clean
	@rm -f $(NAME) $(NAME2)
	@echo "\x1b[31m\x1b[1mExecutable deleted ✖\x1b[0m"

local_re: local_fclean all

re: fclean all
