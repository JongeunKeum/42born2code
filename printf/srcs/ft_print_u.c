/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:13:22 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/27 19:09:47 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

unsigned long long	get_num_u(va_list args, t_obj *obj)
{
	unsigned long long	n;

	if (obj->length == 3)
		n = va_arg(args, unsigned long);
	else if (obj->length == 4)
		n = va_arg(args, unsigned long long);
	else if (obj->length == 2)
		n = (unsigned char)va_arg(args, int);
	else if (obj->length == 1)
		n = (unsigned short)va_arg(args, int);
	else
		n = va_arg(args, unsigned int);
	if (obj->sign)
		obj->space = 0;
	return (n);
}

int					print_unsigned_int(va_list args, t_obj *obj)
{
	unsigned long long	n;
	char				*nbr;

	n = get_num_u(args, obj);
	if (!(nbr = ft_ulltoa(n)))
		return (0);
	obj->len = ft_strlen(nbr);
	if (obj->precision > obj->len)
	{
		if (!(fill_precision_nbr(obj)))
		{
			free(nbr);
			return (0);
		}
	}
	if (n != 0 || (!obj->dot || obj->precision))
	{
		if (!(obj->res = ft_strjoin(obj->res, nbr + obj->neg)))
		{
			free(nbr);
			return (0);
		}
	}
	free(nbr);
	if (obj->width > (int)ft_strlen(obj->res))
	{
		if (!(fill_width(obj)))
			return (0);
	}
	else
	{
		if (obj->space)
			obj->res = ft_strjoin(" ", obj->res);
		else if (obj->sign)
			obj->res = ft_strjoin("+", obj->res);
		if (!obj->res)
			return (0);
	}
	ft_putstr_fd(obj->res, 1);
	obj->return_value += ft_strlen(obj->res);
	return (1);
}
