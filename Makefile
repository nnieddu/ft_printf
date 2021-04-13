# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/10 14:33:30 by ninieddu          #+#    #+#              #
#    Updated: 2021/04/09 14:44:46 by ninieddu         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC		=	gcc -Wall -Wextra -Werror

NAME	=	libftprintf.a

SRCS	=	ft_printf.c\
			ft_fill_cs.c\
			ft_fill_di.c\
			ft_fill_xx.c\
			ft_fill_pu.c\
			ft_printf_utils.c\
			ft_printf_utils_n.c\

OPATH	=	objs/

OBJS	=	$(SRCS:%.c=$(OPATH)%.o)

all: $(NAME)

$(OPATH)%.o	:	%.c
				$(shell mkdir -p objs)
				$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS) $(OPATH)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all fclean clean re
