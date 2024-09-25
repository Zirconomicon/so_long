NAME = so_long

SRCS = main.c so_long.c parsing_utils.c parsing_utils_II.c map_parsing.c event_handlers.c

OBJS = $(SRCS:.c=.o)

CC = gcc

LIB = libft/libft.a ft_printf/libftprintf.a get_next_line/get_next_line.a minilibx_opengl_20191021/libmlx.a

PARAM = -framework OpenGL -framework AppKit

CFLAGS = -Wall -Werror -Wextra -g3

RM = rm -f

all: $(NAME)

$(NAME) : $(OBJS)
	make -C get_next_line/
	make -C ft_printf/
	make -C libft/
	make -C minilibx_opengl_20191021/
	$(CC) $(CFLAGS) $(OBJS) $(LIB) $(PARAM) -o $(NAME)
clean :
	$(RM) $(OBJS) get_next_line/*.o ft_printf/*.o libft/*.o minilibx_opengl_20191021/.o

fclean : clean
	$(RM) $(NAME) get_next_line/get_next_line.a ft_printf/libftprintf.a libft/libft.a minilibx_opengl_20191021/libmlx.a

re : fclean all

.PHONY : all clean fclean re
