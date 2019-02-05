cmake_minimum_required(VERSION 3.12)
project(ft_printf C)

set(CMAKE_C_STANDARD 99)

include_directories(../../Desktop/My_projects/ft_printf)

add_executable(ft_printf
        ft_printf.h
        flags.c
        conv_c.c
        conv_s.c
        conv_p.c
        conv_d.c
        conv_o.c
        conv_x.c
		conv_u.c
        help.c
        ft_strlen.c
        ft_atoi.c
        ft_itoa.c
        ft_putchar.c
        ft_putnbr.c
        ft_putstr.c
        ft_strchr.c
		ft_printf.c
        main.c
        ft_itoa_base.c
		scan_conv.c
		conv_f.c
		float_str.c
		ft_strcmp.c)