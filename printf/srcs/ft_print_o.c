/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 16:42:37 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/29 17:03:30 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static unsigned long long	get_num_o(va_list args, t_obj *obj)
{
	unsigned long long	n;

	if (obj->length == 3)
		n = va_arg(args, unsigned long);
	else if (obj->length == 4)
		n = va_arg(args, unsigned long long);
	else if (obj->length == 1)
		n = (unsigned short)va_arg(args, int);
	else if (obj->length == 2)
		n = (unsigned char)va_arg(args, int);
	else
		n = va_arg(args, unsigned int);
	return (n);
}

static int					process_width_o(unsigned long long n, t_obj *obj)
{
	if (n == 0)
		obj->prefix = 0;
	if (obj->width > (int)ft_strlen(obj->res) + obj->prefix)
	{
		if (!(fill_width(obj)))
			return (0);
	}
	else
	{
		if (obj->prefix & (!obj->dot || !obj->precision))
		{
			if (!(obj->res = ft_strjoin_free("0", obj->res, 2)))
				return (0);
		}
	}
	return (1);
}

static int					process_precision_o(unsigned long long n,
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
		if (!(obj->res = ft_strjoin_free(obj->res, nbr, 1)))
		{
			free(nbr);
			return (0);
		}
	}
	return (1);
}

int							print_oct(va_list args, t_obj *obj)
{
	unsigned long long	n;
	char				*nbr;

	obj->res = (char *)ft_calloc(1, 1);
	n = get_num_o(args, obj);
	if (!(nbr = ft_ulltoa(n)))
		return (0);
	if (n != 0)
	{
		if (!(nbr = ft_convert_base(nbr, "0123456789", "01234567")))
		{
			free(nbr);
			return (0);
		}
	}
	obj->len = ft_strlen(nbr);
	if (!(process_precision_o(n, nbr, obj)))
		return (0);
	free(nbr);
	if (!(process_width_o(n, obj)))
		return (0);
	ft_putstr_fd(obj->res, 1);
	obj->return_value += ft_strlen(obj->res);
	free(obj->res);
	return (1);
}
