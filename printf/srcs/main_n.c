#include <stdio.h>
#include "../includes/ft_printf.h"

int		ft_printf(const char *str, ...);

int		main(void)
{
	int		a;
	int		b;

	a = 123;
	b = 123;
	printf("return:%d\n", printf("01. hello %d world %n|\n    a = %d\n", a, &a, a));
	printf("01. a = %d\n\n", a);
	printf("return:%d\n", ft_printf("01. hello %d world %n|\n    b = %d\n", b, &b, b));
	ft_printf("01. b = %d\n\n", b);

	return (0);
}
