#include <stdio.h>
#include "../includes/ft_printf.h"

int	main(void)
{
/*	printf("01. hello %f world\n", 2.625);
	ft_printf("01. hello %f world\n", 2.625);
	ft_printf("01. hello %f world\n", 0.625);
	printf("\n");

	ft_printf("02. hello %f world\n", 5.125);
	ft_printf("02. hello %f world\n", 0.125);
	printf("\n");
*/
	ft_printf("03. hello %f world\n", __DBL_MIN__);
	ft_printf("03. hello %f world\n", 0.456);
	printf("\n");
/*
	ft_printf("04. hello %f world\n", 12.3125);
	ft_printf("04. hello %f world\n", 0.3125);
	printf("\n");
*/	
	return (0);
}
