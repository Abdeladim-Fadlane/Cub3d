NAME = libft.a
CFILES = ft_atoi.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_substr.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_itoa.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_putchar_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_putstr_fd.c\
		ft_split.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strmapi.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strtrim.c\
		ft_tolower.c\
		ft_toupper.c

OBJ = ${CFILES:.c=.o}
FLAGS = -Wall -Werror -Wextra
CC = gcc-11 $(FLAGS)
LI = ar -rc

all : ${NAME}

${NAME} : ${OBJ}
	${LI} ${NAME} ${OBJ}

${OBJ} :
	${CC} -c ${CFILES} 

clean :
	${RM} ${OBJ}
fclean : clean 
	${RM} ${NAME}
re : fclean all
