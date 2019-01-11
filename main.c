#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main(void)
{
	ft_putstr("-->");
	printf("<-- ft_printf | exit code - %d\n-->", ft_printf("%15.4d", -424242));
	printf("<-- printf    | exit code - %d",         printf("%.200f", 3.14f));
	return (0);
}