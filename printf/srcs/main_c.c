#include <stdio.h>
#include "../includes/ft_printf.h"

int	main(void)
{
	// printf("01. hell%c %corld\n", 'o', 'W');
	// ft_printf("01. hell%c %corld\n\n", 'o', 'W');

	// printf("02. hell%5c\n", 'o');
	// ft_printf("02. hell%5c\n\n", 'o');

	// printf("%d\n", printf("03. hell%c|\n", '\0'));
	// printf("%d\n", ft_printf("03. hell%c|\n\n", '\0'));

	// printf("04. hell%-5c|\n", '\0');
	// ft_printf("04. hell%-5c|\n\n", '\0');

	ft_printf("05. hell%#5c\n", 'o');

	return (0);
}
