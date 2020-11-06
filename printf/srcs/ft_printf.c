/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:25:31 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/06 21:41:49 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_printf.h"

t_obj	*init_objs(void)
{
	t_obj	*obj;

	if (!(obj = (t_obj *)malloc(sizeof(t_obj))))
		return (NULL);
	obj->left = 0;
	obj->zero = 0;
	obj->sign = 0;
	obj->space = 0;
	obj->prefix = 0;
	obj->width = 0;
	obj->precision = 0;
	obj->type = 0;
	obj->len = 0;
	obj->idx = 0;
	obj->neg = 0;
	return (obj);
}

void	set_objs(t_obj *obj)
{
	obj->left = 0;
	obj->zero = 0;
	obj->sign = 0;
	obj->space = 0;
	obj->prefix = 0;
	obj->width = 0;
	obj->precision = 0;
	obj->type = 0;
	obj->len = 0;
	obj->neg = 0;
}

int		ft_printf(const char *str, ...)
{	// 반환값 고치기 모ㅇ총ㅇ아
	va_list	args;
	t_obj	*obj;

	va_start(args, str);
	obj = init_objs();
	while (str[obj->idx])
	{
		if (str[obj->idx] == '%')
		{
			if (!check_format(str, args, obj))
				return (-1);
			set_objs(obj);
		}
		else
			write(1, &str[obj->idx], 1);
		obj->idx++;
	}
	va_end(args);
	return (obj->idx);
}

int		main(void)
{
	printf("01. hello %d world %10d\n", 12345, -9876);
	ft_printf("01. hello %d world %10d\n\n", 12345, -9876);

	printf("02. hello %d world\n", -12345);
	ft_printf("02. hello %d world\n\n", -12345);

	printf("03. hello %10d world\n", 12345);
	ft_printf("03. hello %10d world\n\n", 12345);

	printf("03. hello %-10d world\n", 12345);
	ft_printf("03. hello %-10d world\n\n", 12345);

	printf("04. hello %4d world\n", 12345);
	ft_printf("04. hello %4d world\n\n", 12345);

	printf("05. hello %4d world\n", -12345);
	ft_printf("05. hello %4d world\n\n", -12345);

	printf("06. hello %10.5d world\n", 123);
	ft_printf("06. hello %10.5d world\n\n", 123);

	printf("07. hello %10.5d world\n", -123);
	ft_printf("07. hello %10.5d world\n\n", -123);

	printf("08. hello %10.1d world\n", 123);
	ft_printf("08. hello %10.1d world\n\n", 123);

	printf("09. hello %10.1d world\n", -123);
	ft_printf("09. hello %10.1d world\n\n", -123);

	printf("10. hello %2.5d world\n", 123);
	ft_printf("10. hello %2.5d world\n\n", 123);

	printf("11. hello %2.5d world\n", -123);
	ft_printf("11. hello %2.5d world\n\n", -123);

	printf("12. hello %2.2d world\n", 123);
	ft_printf("12. hello %2.2d world\n\n", 123);

	printf("13. hello %2.2d world\n", -123);
	ft_printf("13. hello %2.2d world\n\n", -123);

	printf("14. hello %.2d world\n", 123);
	ft_printf("14. hello %.2d world\n\n", 123);

	printf("15. hello %.2d world\n", -123);
	ft_printf("15. hello %.2d world\n\n", -123);

	printf("16. hello %.6d world\n", 123);
	ft_printf("16. hello %.6d world\n\n", 123);

	printf("17. hello %.6d world\n", -123);
	ft_printf("17. hello %.6d world\n\n", -123);

	return (0);
}
