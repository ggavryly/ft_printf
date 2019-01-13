cmake_minimum_required(VERSION 3.12)
project(printf1 C)

set(CMAKE_C_STANDARD 99)

include_directories(../../Desktop/printf0)

add_executable(printf1
        ../../Desktop/printf0/ft_printf.h
        ../../Desktop/printf0/flags.c
        ../../Desktop/printf0/conv_c.c
        ../../Desktop/printf0/conv_s.c
        ../../Desktop/printf0/conv_p.c
        ../../Desktop/printf0/conv_d.c
        ../../Desktop/printf0/conv_o.c
        ../../Desktop/printf0/conv_x.c
		../../Desktop/printf0/conv_u.c
        ../../Desktop/printf0/help.c
        ../../Desktop/printf0/ft_strlen.c
        ../../Desktop/printf0/ft_atoi.c
        ../../Desktop/printf0/ft_itoa.c
        ../../Desktop/printf0/ft_putchar.c
        ../../Desktop/printf0/ft_putnbr.c
        ../../Desktop/printf0/ft_putstr.c
        ../../Desktop/printf0/ft_strchr.c
		../../Desktop/printf0/ft_printf.c
        ../../Desktop/printf0/main.c
        ../../Desktop/printf0/ft_itoa_base.c
        ../../Desktop/printf0/ft_atoi_base.c
		../../Desktop/printf0/scan_conv.c
		)