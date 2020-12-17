#include <stdio.h>
#include "../includes/ft_printf.h"
#include <time.h>

int	main(void)
{
	time_t start, end;
	double result;

	start = time(NULL);

	printf("10:\t\t%d\n", 10);
	ft_printf("10:\t\t%d\n\n", 10);

	printf("2147483647(l):%d\n", 2147483647);
	ft_printf("2147483647(l):%d\n\n", 2147483647);

	printf("2147483648(l):%ld\n", 2147483648);
	ft_printf("2147483649(l):%ld\n\n", 2147483649);

	printf("4294967295(l):%ld\n", 4294967295);
	ft_printf("4294967295(l):%ld\n\n", 4294967295);

	printf("LLONG_MIN(ll):%lld\n", LLONG_MIN);
	ft_printf("LLONG_MIN(ll):%lld\n\n", LLONG_MIN);

	printf("LLONG_MAX(ll):%lld\n", LLONG_MAX);
	ft_printf("LLONG_MAX(ll):%lld\n\n", LLONG_MAX);

	end = time(NULL);
	result = (double)(end - start);
	printf("%f", result);

	return (0);
}
