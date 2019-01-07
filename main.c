#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main(void)
{
    ft_putstr("-->");
    printf("<-- ft_printf | exit code - %d\n-->", ft_printf("%.s", "egg"));
    printf("<-- printf    | exit code - %d",         printf("%.s", "ege"));
    return (0);
}