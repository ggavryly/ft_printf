#include <stdio.h>
#include "../../../.Trash/ft_printf/ft_printf.h"

int main()
{
    long double k = 16.754;
    ft_putstr("-->");
    printf("<-- ft_printf | exit code - %d\n-->", ft_printf("%-10.3s", NULL));
    printf("<-- printf    | exit code - %d",         printf("%-10.3s", NULL));
    return (0);
}