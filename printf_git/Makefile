# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbritani <sbritani@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/13 22:47:41 by sbritani          #+#    #+#              #
#    Updated: 2022/10/28 19:14:27 by sbritani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror

SRCS=ft_printf.c\
print.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SRCS) $(OBJS) 
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJS) $(BONUSOBJS) $(LIBFT)

fclean: clean
	rm -f $(NAME)

re: fclean all
