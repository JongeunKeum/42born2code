#include <stdio.h>
#include "../includes/ft_printf.h"

int	main(void)
{
	ft_printf("%g", 12.345);
	printf("\n");
	ft_printf("%e", 12.345);
	printf("\n");
	ft_printf("%z", 12);
	printf("\n");
	return (0);
}
