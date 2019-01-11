#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main(void)
{
	ft_putstr("-->");
	printf("<-- ft_printf | exit code - %d\n-->", ft_printf("%lu", -42));
	printf("<-- printf    | exit code - %d",         printf("%lu", -42));
	return (0);
}