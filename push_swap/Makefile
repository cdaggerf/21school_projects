# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/03 18:36:53 by cdaggerf          #+#    #+#              #
#    Updated: 2021/12/11 21:17:41 by cdaggerf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS	=	ft_push_swap.c main.c push_a_b.c reverse_a_b.c \
			rotate_a_b.c swap_a_b.c utils.c utilss.c utilsss.c \
			ft_split.c

OBJ		=	ft_push_swap.o main.o push_a_b.o reverse_a_b.o \
			rotate_a_b.o swap_a_b.o utils.o utilss.o utilsss.o \
			ft_split.o

all: $(NAME)

$(NAME): $(SRCS)
	@gcc -Wall -Wextra -Werror $(SRCS) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re : fclean all