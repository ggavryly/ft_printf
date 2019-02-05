#include <stdio.h>
#include "../../../.Trash/ft_printf/ft_printf.h"

int main()
{
    int k = 1000;
    ft_putstr("-->");
    printf("<-- ft_printf | exit code - %d\n-->", ft_printf("%d", -1));
    printf("<-- printf    | exit code - %d",         printf("%d", -1));
    return (0);
}