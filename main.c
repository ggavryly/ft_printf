#include <stdio.h>
#include "../../../.Trash/ft_printf/ft_printf.h"

int main()
{
    long double k = 16.754;
    ft_putstr("-->");
    printf("<-- ft_printf | exit code - %d\n-->", ft_printf("%f", 16));
    printf("<-- printf    | exit code - %d",         printf("%f", 16));
    return (0);
}