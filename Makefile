# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/17 16:41:55 by eenasalorin       #+#    #+#              #
#    Updated: 2020/05/28 17:32:31 by eenasalorin      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select
CFLAGS = -Wall -Wextra -Werror
CC = gcc

INC_DIR := ./includes
SRCS_DIR := ./srcs
OBJ_DIR := ./obj

SRCS :=	main.c \
		max_len.c \
		se_read.c \
		raw_mode.c \
		free_all.c \
		selection.c \
		se_struct.c \
		move_cursor.c \
		remove_item.c \
		send_choices.c \
		se_print_list.c \
		inspect_controls.c \

OBJ :=	$(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

.PHONY : all clean fclean re

all : $(NAME)

$(OBJ_DIR):
	@/bin/mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:$(SRCS_DIR)/%.c
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<

$(NAME) : $(OBJ_DIR) $(OBJ)
	@echo "\\033[1;33mBuilding libft..\\033[0;39m"
	@make -C libft/
	@echo "\\033[1;33mBuilding ft_select..\\033[0;39m"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft/libft.a -ltermcap
	@echo "\\033[1;32mDONE\\033[0;39m"
	@echo "\n\\033[1;37mUsage: <command> 'ft_select [arg1, ...]'\\033[0;39m"

clean :
	@echo "\\033[1;31mCleaning ft_select object files..\\033[0;39m"
	@rm -f $(OBJ)
	@echo "\\033[1;31mCleaning libft object files..\\033[0;39m"
	@make clean -C libft/

fclean : clean
	@echo "\n\\033[1;37mCleaning executables..\\033[0;39m"
	@rm -f $(NAME)
	@make fclean -C libft/

se : $(OBJ_DIR) $(OBJ)
	@echo "\\033[1;33mBuilding project..\\033[0;39m"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft/libft.a -ltermcap
	@echo "\\033[1;32mDONE\\033[0;39m"
	@echo "\n\\033[1;37mUsage: <command> 'ft_select [arg1, ...]'\\033[0;39m"
	@make clean

re : fclean all
