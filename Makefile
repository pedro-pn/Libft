FILES	=	ft_isalpha.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \

OBJS = ${FILES:.c=.o}

CC = gcc

FLAGS = -Werror -Wall -Wextra

NAME = libft.a

OUTPUT = teste.out

%.o:%.c
	${CC} ${FLAGS} -c -o $@ $^

all: libft

tt: libft
	${CC} ${FLAGS} main_libft.c -o ${OUTPUT} -L. -lft -lbsd && ./${OUTPUT}

libft: ${OBJS}
		@ ar rc ${NAME} ${OBJS}

clean: 
		@ rm -f *.o

fclean: clean
		@ rm ${NAME} && rm ${OUTPUT}

norma:
		@ norminette -R CheckForbiddenSourceHeader ${FILES}