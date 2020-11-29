CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rc
NAME = libftprintf.a
SRCS = ./srcs/ft_printf.c  ./srcs/ft_printf_utils.c\
	   ./srcs/ft_chk_format.c ./srcs/ft_lltoa.c \
	   ./srcs/ft_print_d.c ./srcs/ft_print_u.c \
	   ./srcs/ft_print_c.c ./srcs/ft_print_s.c \
	   ./srcs/ft_print_hex.c ./srcs/ft_print_o.c\
	   ./srcs/ft_print_p.c ./srcs/ft_print_n.c \
	   ./srcs/ft_convert_base.c ./srcs/ft_ptoa.c \
	   ./srcs/ft_fill_width.c ./srcs/ft_ulltoa.c \
	   ./srcs/ft_strjoin_free.c

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
