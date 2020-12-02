#include <stdio.h>
#include "../includes/ft_printf.h"

int	main(void)
{
	printf("01. hello %f world\n", 2.625);
	ft_printf("01. hello %f world\n", 2.625);
	ft_printf("01. hello %f world\n", 0.625);

	ft_printf("02. hello %f world\n", 5.125);
	ft_printf("02. hello %f world\n", 0.125);

	ft_printf("03. hello %f world\n", 23.456);
	ft_printf("03. hello %f world\n", 0.456);
	
	return (0);
}
