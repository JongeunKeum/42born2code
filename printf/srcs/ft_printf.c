/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:25:31 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/26 17:44:06 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	obj->dot = 0;
	obj->length = 0;
	obj->return_value = 0;
	if (!(obj->res = (char *)ft_calloc(1, 1)))
		return (NULL);
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
	obj->dot = 0;
	obj->length = 0;
	if (!(obj->res = (char *)ft_calloc(1, 1)))
		return ;
}

int		ft_printf(const char *str, ...)
{
	va_list	args;
	t_obj	*obj;
	int		result;

	va_start(args, str);
	if (!(obj = init_objs()))
		return (-1);
	while (str[obj->idx])
	{
		if (str[obj->idx] == '%')
		{
			if (!check_format(str, args, obj))
			{
				free(obj->res);
				free(obj);
				return (-1);
			}
			free(obj->res);
			set_objs(obj);
		}
		else
		{
			write(1, &str[obj->idx], 1);
			obj->return_value++;
		}
		obj->idx++;
	}
	va_end(args);
	free(obj->res);
	result = obj->return_value;
	free(obj);
	return (result);
}
