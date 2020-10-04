# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/02 15:58:25 by jkeum             #+#    #+#              #
#    Updated: 2020/10/04 20:30:20 by jkeum            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
AR = ar
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
INCLUDES = libft.h
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	   ft_isprint.c ft_isupper.c ft_islower.c \
	   ft_strlen.c ft_strlcpy.c
OBJS = ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o \
	   ft_isprint.o ft_isupper.o ft_islower.o \
	   ft_strlen.o ft_strlcpy.o
RM = rm -f

all : $(NAME)

.c.o :
	$(CC) $(CFLAGS) -I . -c $< -o $(<:.c=.o)

$(NAME) : $(INCLUDES) $(OBJS)
	$(AR) rc $@ $^
	ranlib $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
