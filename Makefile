NAME = parsing

SRCS = parsing_utils.c parsing_utils_II.c main.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra
 
RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	make -C get_next_line/
	make -C ft_printf/
	make -C libft/
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) get_next_line/get_next_line.a ft_printf/libftprintf.a libft/libft.a

clean :
	$(RM) $(OBJS) get_next_line/*.o ft_printf/*.o libft/*.o

fclean : clean
	$(RM) $(NAME) get_next_line/get_next_line.a ft_printf/libftprintf.a libft/libft.a

re : fclean all

.PHONY : all clean fclean re
