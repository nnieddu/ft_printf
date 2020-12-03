# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ninieddu <ninieddu@student.le-101.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/10 14:33:30 by ninieddu          #+#    #+#              #
#    Updated: 2020/12/03 17:00:34 by ninieddu         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC		=	gcc -Wall -Wextra -Werror

NAME	=	libftprintf.a

EXEC	=	a.out

SRCS	=	ft_printf.c\
			ft_fill_cs.c\
			ft_fill_di.c\
			ft_fill_xx.c\
			ft_fill_pu.c\
			ft_printf_utils.c\
			ft_printf_utils_n.c\

OBJ		=	$(SRCS:.c=.o) 

all: 	$(NAME)

$(OBJ) : ft_printf.h

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(EXEC)

re : fclean all

.PHONY: all fclean clean re
