#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main(void)
{
	ft_putstr("-->");
	printf("<-- ft_printf | exit code - %d\n-->", ft_printf("{%05.s}", 0));
	printf("<-- printf    | exit code - %d",         printf("{%05.s}", 0));

	printf("\n");
	float f = 0.15625;
	unsigned int a;
	unsigned int * ptr_tmp = (unsigned int *)(&f);
	a=*ptr_tmp;


	unsigned int tableau[32];
	int machaine[32];
	unsigned int som=1;
	int i;

	for(i=0;i<32;i++)
	{
		tableau[i]=som;
		som=som*2;
	}

	unsigned int  resultat;


	for(i=0;i<=32;i++)
	{
		resultat = a & tableau[i];
		if( resultat == tableau[i] )
		{ machaine[i]=1;  }
		else
		{ machaine[i]=0;}
	}

	fprintf(stdout,"binary - float : ");
	for(i=31;i>=0;i--)
	{

		fprintf(stdout,"%d",machaine[i]);

	}

	fprintf(stdout,"\n");
	fprintf(stdout,"f  : %f\n",f );
	fprintf(stdout,"e  : %e\n",f );
	fprintf(stdout,"g  : %g\n",f );
	return (0);
}