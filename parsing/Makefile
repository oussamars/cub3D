SRCS =	main_parsing.c config.c file_checker.c map_checker.c read_map.c check_characters.c \
		libft/ft_split.c libft/helper_functions1.c libft/helper_functions2.c libft/ft_malloc.c \
		../get_next_line/get_next_line.c \
		../get_next_line/get_next_line_utils.c \

CC = cc

# CFLAGS = -Wall -Wextra -Werror  -fsanitize=address -g3
CFLAGS = -Wall -Werror -Wextra 

NAME = Cub3D


OBJECTS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

# MLX = -Lminilibx-linux -lmlx -lXext -lX11

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
# 	$(CC) $(CFLAGS) $(OBJECTS) $(MLX) -o $(NAME)

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re

.SECONDARY : $(OBJECTS)