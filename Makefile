.PHONY: all clean fclean re
NAME = libftprintf.a

SRC =	ft_strlen.c \
		ft_strchr.c \
		ft_atoi.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putnbr.c \
		scan_conv.c \
		conv_c.c \
		conv_s.c \
		conv_p.c \
		conv_d.c \
		conv_x.c \
		conv_o.c \
		conv_u.c \
		ft_printf.c \
		flags.c \
		ft_atoi_base.c \
		ft_itoa_base.c \
		help.c 


SRO = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRC) -I ft_printf.h
	ar rcs $(NAME) $(SRO)

clean:
	rm -f $(SRO)

fclean: clean
	rm -f $(NAME)

re: fclean all