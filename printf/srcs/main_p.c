#include <stdio.h>
#include "../includes/ft_printf.h"

int	ft_printf(const char *str, ...);

int	main(void)
{
	int	i;
	char	a[10] = "abcdefg";

	i = 2;
	printf("return:%d\n", printf("00. hello %p world %10p\n", &i, &i));
	printf("return:%d\n", ft_printf("00. hello %p world %10p\n\n", &i, &i));
	
	printf("01. hello %20p world\n", &a);
	ft_printf("01. hello %20p world\n\n", &a);
	
	printf("02. hello %-20p%-20pworld\n", &a, "abc");
	ft_printf("02. hello %-20p%-20pworld\n\n", &a, "abc");
	
	printf("03. hello %.p world\n", &a);
	ft_printf("03. hello %.p world\n\n", &a);
	
//	printf("04. hello %.20p world\n", &a);
	ft_printf("04. hello %.20p world\n\n", &a);
	
	printf("05. hello %p world\n", "abc");
	ft_printf("05. hello %p world\n\n", "abc");
	
	printf("06. hello %p world\n", NULL);
	ft_printf("06. hello %p world\n\n", NULL);
	
	printf("07. hello %% world\n");
	ft_printf("07. hello %% world\n\n");
	
	printf("08. hello %5% world\n");
	ft_printf("08. hello %5% world\n\n");
	
	printf("09. hello %-5% world\n");
	ft_printf("09. hello %-5% world\n\n");
	
	printf("10. hello %05% world\n");
	ft_printf("10. hello %05% world\n\n");
	
	printf("11. hello %-05% world\n");
	ft_printf("11. hello %-05% world\n\n");
	
	printf("12. hello %-16p%-16p%-16p%-16p%-16p world\n", &a, &a[1], &a[2], &a[3], &a[4]);
	ft_printf("12. hello %-16p%-16p%-16p%-16p%-16p world\n\n", &a, &a[1], &a[2], &a[3], &a[4]);
	
	printf("%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10);
	ft_printf("%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10);

	return (0);
}
