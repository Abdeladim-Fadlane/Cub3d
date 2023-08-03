NAME = cub_3d
CFILESLG = getnextline/get_next_line.c\
		 getnextline/get_next_line_utils.c\
		 libft/ft_atoi.c\
		libft/ft_bzero.c\
		libft/ft_calloc.c\
		libft/ft_substr.c\
		libft/ft_isalnum.c\
		libft/ft_isalpha.c\
		libft/ft_isascii.c\
		libft/ft_isdigit.c\
		libft/ft_isprint.c\
		libft/ft_itoa.c\
		libft/ft_memcmp.c\
		libft/ft_memcpy.c\
		libft/ft_memmove.c\
		libft/ft_memset.c\
		libft/ft_putchar_fd.c\
		libft/ft_putendl_fd.c\
		libft/ft_putnbr_fd.c\
		libft/ft_putstr_fd.c\
		libft/ft_split.c\
		libft/ft_strchr.c\
		libft/ft_strdup.c\
		libft/ft_strjoin.c\
		libft/ft_strlcat.c\
		libft/ft_strlcpy.c\
		libft/ft_strlen.c\
		libft/ft_strmapi.c\
		libft/ft_strncmp.c\
		libft/ft_strnstr.c\
		libft/ft_strrchr.c\
		libft/ft_tolower.c\
		libft/ft_toupper.c\

CFILES = main.c\
		check_map_name.c\
		check_map_in_fd.c\
		check_main_map.c\
		norm.c\
		norm1.c\
		norm2.c\
		norm3.c\
		norm4.c\
		norm5.c\
		cub3d.c\
		raycasting_horizontal.c \
		raycasting_vertical.c \
		inisiall.c \
		player_moves.c  \
		cub3d_utils.c \
		motion.c \
		texture.c \
		${CFILESLG} \


OBJ = ${CFILES:.c=.o}


CFLAGS =   -Wall -Werror -Wextra #-fsanitize=address
CC = cc
LI = ar -rc

all : ${NAME}


${NAME} : ${OBJ}
	@cc   $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(CFILES) -o $(NAME) 

clean :
	${RM} ${OBJ}
fclean : clean 
	${RM} ${NAME} 
re : fclean all