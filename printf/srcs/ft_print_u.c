/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:13:22 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/23 13:24:30 by jkeum            ###   ########.fr       */
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

int		print_unsigned_int(va_list args, t_obj *obj)
{
	unsigned long long	n;
	char				*nbr;

	n = get_num_u(args, obj);
	nbr = ft_lltoa(n);
	obj->len = ft_strlen(nbr);
	if (obj->precision > obj->len)
		fill_precision_nbr(obj);
	if (n != 0 || (!obj->dot || obj->precision))
		obj->res = ft_strjoin(obj->res, nbr + obj->neg);
	if (obj->width > (int)ft_strlen(obj->res))
		fill_width(obj);
	else
	{
		if (obj->space)
			obj->res = ft_strjoin(" ", obj->res);
		else if (obj->sign)
			obj->res = ft_strjoin("+", obj->res);
	}
	ft_putstr_fd(obj->res, 1);
	obj->return_value += ft_strlen(obj->res);
	free(nbr);
	return (1);
}
