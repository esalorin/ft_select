# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/22 15:38:44 by esalorin          #+#    #+#              #
#    Updated: 2020/06/04 15:23:36 by esalorin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = srcs/ft_printf.c srcs/ft_print_csp.c srcs/ft_print_dioux.c srcs/ft_print_flags.c \
srcs/ft_dioux_flags.c srcs/ft_print_double.c srcs/ft_check_dioux.c srcs/ft_memset.c \
srcs/ft_bzero.c srcs/ft_memcpy.c srcs/ft_memccpy.c srcs/ft_memmove.c srcs/ft_memchr.c \
srcs/ft_memcmp.c srcs/ft_strlen.c srcs/ft_strdup.c srcs/ft_strcpy.c srcs/ft_strncat.c \
srcs/ft_strlcat.c srcs/ft_strrchr.c srcs/ft_strstr.c srcs/ft_strnstr.c srcs/ft_strcmp.c \
srcs/ft_strncmp.c srcs/ft_atoi.c srcs/ft_isalpha.c srcs/ft_isdigit.c srcs/ft_strcat.c \
srcs/ft_isalnum.c srcs/ft_isascii.c srcs/ft_isprint.c srcs/ft_toupper.c srcs/ft_tolower.c \
srcs/ft_strncpy.c srcs/ft_strchr.c srcs/ft_memalloc.c srcs/ft_memdel.c srcs/ft_strnew.c \
srcs/ft_strdel.c srcs/ft_strclr.c srcs/ft_striter.c srcs/ft_striteri.c srcs/ft_strmap.c \
srcs/ft_strmapi.c srcs/ft_strequ.c srcs/ft_strnequ.c srcs/ft_strsub.c srcs/ft_strtrim.c \
srcs/ft_strsplit.c srcs/ft_itoa.c srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_putendl.c \
srcs/ft_putnbr.c srcs/ft_putchar_fd.c srcs/ft_putstr_fd.c srcs/ft_putendl_fd.c srcs/ft_nbrlen.c\
srcs/ft_putnbr_fd.c srcs/ft_strjoin.c srcs/ft_lstnew.c srcs/ft_lstdelone.c srcs/ft_strswap.c \
srcs/ft_itoa_base.c srcs/ft_atoi_base.c srcs/ft_itoa_unsigned.c srcs/ft_ftoa.c srcs/ft_swap.c \
srcs/get_next_line.c srcs/ft_chrcount.c srcs/ft_array_push.c srcs/ft_arraynew.c srcs/ft_arraydel.c \
srcs/ft_array_merge.c srcs/ft_putarray.c srcs/ft_strfound.c srcs/ft_arraydup.c srcs/ft_arrayrem.c \
srcs/ft_joindel.c srcs/ft_rmchr.c srcs/ft_arraylen.c srcs/ft_putint_fd.c

OBJ = ft_printf.o ft_print_csp.o ft_print_dioux.o ft_print_flags.o ft_dioux_flags.o ft_nbrlen.o\
ft_print_double.o ft_check_dioux.o ft_memset.o ft_bzero.o ft_memcpy.o ft_memccpy.o ft_memmove.o \
ft_memchr.o ft_memcmp.o ft_strlen.o ft_strdup.o ft_strcpy.o ft_strncat.o ft_strlcat.o \
ft_strrchr.o ft_strstr.o ft_strnstr.o ft_strcmp.o ft_strncmp.o ft_atoi.o ft_isalpha.o \
ft_isdigit.o ft_strcat.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_toupper.o ft_tolower.o \
ft_strncpy.o ft_strchr.o ft_memalloc.o ft_memdel.o ft_strnew.o ft_strdel.o ft_strclr.o \
ft_striter.o ft_striteri.o ft_strmap.o ft_strmapi.o ft_strequ.o ft_strnequ.o ft_strsub.o \
ft_strtrim.o ft_strsplit.o ft_itoa.o ft_putchar.o ft_putstr.o ft_putendl.o ft_putnbr.o \
ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_strjoin.o ft_lstnew.o \
ft_lstdelone.o ft_itoa_base.o ft_atoi_base.o ft_itoa_unsigned.o ft_ftoa.o ft_strswap.o ft_swap.o \
get_next_line.o ft_chrcount.o ft_array_push.o ft_arraynew.o ft_arraydel.o ft_array_merge.o \
ft_putarray.o ft_strfound.o ft_arraydup.o ft_arrayrem.o ft_joindel.o ft_rmchr.o ft_arraylen.o \
ft_putint_fd.o

INC = srcs/libft.h

.PHONY: clean fclean all re

all : $(NAME)

$(NAME) :
	@gcc -Wall -Wextra -Werror -c $(SRC) $(INC)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
