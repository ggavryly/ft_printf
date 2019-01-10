#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main(void)
{
    ft_putstr("-->");
    printf("<-- ft_printf | exit code - %d\n-->", ft_printf("@moulitest: %5.x %5.0x", 0, 0));
    printf("<-- printf    | exit code - %d",         printf("@moulitest: %5.x %5.0x", 0, 0));
    return (0);
}