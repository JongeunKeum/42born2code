#include <stdio.h>
#include "../includes/ft_printf.h"

int	ft_printf(const char *str, ...);

int	main(void)
{
	printf("01. hell%s %s\n", "o", "World");
	ft_printf("01. hell%s %s\n\n", "o", "World");

	printf("02. %10s\n", "hello");
	ft_printf("02. %10s\n\n", "hello");

	printf("%d\n", printf("03. %-10s|\n", "hello"));
	printf("%d\n", ft_printf("03. %-10s|\n\n", "hello"));

	printf("04. %s|\n", "");
	ft_printf("04. %s|\n\n", "");

	printf("05. %.0s|\n", "hello world");
	ft_printf("05. %.0s|\n\n", "hello wolrd");

	printf("06. %.5s|\n", "hello world");
	ft_printf("06. %.5s|\n\n", "hello wolrd");

	printf("07. %.10s|\n", "hello");
	ft_printf("07. %.10s|\n\n", "hello");

	printf("08. %15.10s|\n", "hello");
	ft_printf("08. %15.10s|\n\n", "hello");

	printf("09. %-15.5s|\n", "hello world");
	ft_printf("09. %-15.5s|\n\n", "hello world");

	printf("10. %5.5s|\n", "hello world");
	ft_printf("10. %5.5s|\n\n", "hello world");

	printf("11. %-5.5s|\n", "hello world");
	ft_printf("11. %-5.5s|\n\n", "hello world");

	printf("12. %10.5s|\n", NULL);
	ft_printf("12. %10.5s|\n\n", NULL);

	return (0);
}
