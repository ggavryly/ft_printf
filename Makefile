NAME = libftprintf.a

INC = -I ./include/

SRCS_NAME = conv_c.c \
			conv_d.c \
			conv_f.c \
			conv_o.c \
			conv_p.c \
			conv_s.c \
			conv_u.c \
			conv_x.c \
			flags.c \
			float_str.c \
			ft_atoi.c \
			ft_itoa_base.c \
			ft_itoa.c \
			ft_printf.c \
			ft_putchar.c \
			ft_putnbr.c \
			ft_putstr.c \
			ft_strchr.c \
			ft_strcmp.c \
			ft_strlen.c \
			help.c \
			scan_conv.c


SRCS_PATH = src/
OBJ_PATH  = obj/

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(SRCS_NAME:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32m\033[1m[√] - Binary \033[1;33m\033[4m\033[1m$(NAME)\033[0m\033[1;0m\033[32m\033[1m created.\033[0m"

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p obj
	@gcc -c $(FLAGS) $(INC) $< -o $@
	@echo "\033[32m\033[1m[√] - Compilation of \033[0m\033[33m\033[1m$(notdir $<)\033[0m\033[32m\033[1m done.\033[0m"

clean:
	@/bin/rm -rf $(OBJ_PATH)
	@echo "\033[31m\033[1m[X] - Objects files $(OBJS_LIST)removed.\033[0m"

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "\033[31m\033[1m[X] - Bin \033[4m$(NAME)\033[0m \033[31m\033[1mremoved.\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re
