#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main(void)
{
    ft_putstr("-->");
    printf("<-- ft_printf | exit code - %d\n-->", ft_printf("%.0p, %.p", 0, 0));
    printf("<-- printf    | exit code - %d",         printf("%.0p, %.p", 0, 0));
    return (0);
}