CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rc
NAME = libftprintf.a
SRCS = ./srcs/test.c
OBJS = $(SRCS:.c=.o)
LIB = libft.a
LIB_DIR = ./libft
INC = ./includes
RM = rm -f

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -I$(INC) -o $@ $<

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIB_DIR)
	cp $(LIB_DIR)/$(LIB) ./$(NAME)
	$(AR) $(ARFLAGS) $@ $(OBJS)

clean :
	$(MAKE) -C $(LIB_DIR) fclean
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
