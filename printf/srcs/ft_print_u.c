/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:13:22 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/29 17:05:16 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static unsigned long long	get_num_u(va_list args, t_obj *obj)
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

static int					process_precision_u(unsigned long long n,
		char *nbr, t_obj *obj)
{
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
		if (!(obj->res = ft_strjoin_free(obj->res, nbr + obj->neg, 1)))
		{
			free(nbr);
			return (0);
		}
	}
	return (1);
}

static int					process_width_u(t_obj *obj)
{
	if (obj->width > (int)ft_strlen(obj->res))
	{
		if (!(fill_width(obj)))
			return (0);
	}
	else
	{
		if (obj->space)
			obj->res = ft_strjoin_free(" ", obj->res, 2);
		else if (obj->sign)
			obj->res = ft_strjoin_free("+", obj->res, 2);
		if (!obj->res)
			return (0);
	}
	return (1);
}

int							print_unsigned_int(va_list args, t_obj *obj)
{
	unsigned long long	n;
	char				*nbr;

	obj->res = (char *)ft_calloc(1, 1);
	n = get_num_u(args, obj);
	if (!(nbr = ft_ulltoa(n)))
		return (0);
	obj->len = ft_strlen(nbr);
	if (!(process_precision_u(n, nbr, obj)))
		return (0);
	free(nbr);
	if (!(process_width_u(obj)))
		return (0);
	ft_putstr_fd(obj->res, 1);
	obj->return_value += ft_strlen(obj->res);
	free(obj->res);
	return (1);
}
