# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iduric <iduric@42lausanne.ch>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 19:36:54 by iduric            #+#    #+#              #
#    Updated: 2024/08/29 16:48:37 by iduric           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_isalnum.c ft_isdigit.c ft_memset.c ft_strjoin.c ft_tolower.c \
ft_isalpha.c ft_isprint.c ft_split.c ft_strlen.c ft_strtrim.c ft_toupper.c \
ft_bzero.c ft_isascii.c ft_memcpy.c ft_strrchr.c ft_substr.c ft_strchr.c \
ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
ft_itoa.c ft_strdup.c ft_calloc.c ft_striteri.c ft_strmapi.c ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strncmp.c\

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

CC		= gcc
RM		= rm -f

CFLAGS 	= -Wall -Wextra -Werror

all:		${NAME}

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}

clean:  
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY	: all clean fclean re