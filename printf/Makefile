CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rc
NAME = libftprintf.a
SRCS = ./srcs/ft_printf.c ./srcs/ft_print_d.c \
	   ./srcs/chk_format.c ./srcs/ft_lltoa.c \
	   ./srcs/ft_print_c.c ./srcs/ft_print_s.c 
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
