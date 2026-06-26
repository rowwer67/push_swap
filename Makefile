# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrezden <abrezden@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/21 13:45:55 by abrezden          #+#    #+#              #
#    Updated: 2026/06/26 13:47:05 by abrezden         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -g -Wall -Wextra -Werror -I.

SRCS = main__.c \
	parsing.c \
	bench.c \
	disorder.c \
	op_push.c \
	stack_utils.c \
	op_swap.c \
	op_rotate.c \
	op_reverse_rotate.c \
	alg_simple_sort.c \
	alg_sort_stack.c \
	alg_bucket_sort.c \
	alg_bucket_sort_functions.c \
	alg_radix_sort.c \
	alg_radix_sort_index.c \
	libft/ft_atoi_mod.c \
	libft/ft_lstaddback.c \
	libft/ft_lstnew.c \
	libft/ft_putnbr_fd.c \
	libft/ft_putstr_fd.c \
	libft/ft_strcmp.c \
	libft/ft_strlen.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re