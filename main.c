#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main(void)
{
	ft_putstr("-->");
	printf("<-- ft_printf | exit code - %d\n-->", ft_printf("%#09.0X", 482));
	printf("<-- printf    | exit code - %d",         printf("%#09.0X", 482));
	return (0);
}
