#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main(void)
{
	int i;
	ft_putstr("-->");
	printf("<-- ft_printf | exit code - %d\n-->", ft_printf("%#p", &i));
	printf("<-- printf    | exit code - %d",         printf("%#p", &i));
	return (0);
}