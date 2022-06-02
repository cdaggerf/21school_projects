NAME = libftprintf.a
LIBFT = libft
LIBFT_LIB = libft.a

SRCS = ft_printf.c \
	   ft_flags.c \
	   ft_start.c \
	   ft_print_c.c \
	   ft_print_id.c \
	   ft_print_neg_id.c \
	   ft_print_p.c \
	   ft_print_str.c \
	   ft_print_u.c \
	   ft_print_x.c \
	   ft_print_xxx.c
INCLUDE = ft_printf.h
OBJS = ${SRCS:.c=.o}
RM = rm -rf

LIBC = ar rcs
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCLUDE}

${NAME} : ${OBJS}
	make all -C ${LIBFT}/
	cp ${LIBFT}/${LIBFT_LIB} ${NAME}
	${LIBC} ${NAME} ${OBJS}

clean:
		${RM} ${OBJS}
		make clean -C ${LIBFT}

fclean: clean
		${RM} ${NAME}
		make fclean -C ${LIBFT}

re: fclean all

.PHONY: all clean fclean re