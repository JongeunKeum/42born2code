/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 16:42:37 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/23 16:23:22 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

unsigned long long	get_num_o(va_list args, t_obj *obj)
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

void				process_width_o(t_obj *obj)
{
	if (obj->width > (int)ft_strlen(obj->res) + obj->prefix)
		fill_width(obj);
	else
	{
		if (obj->prefix & (!obj->dot || !obj->precision))
			obj->res = ft_strjoin("0", obj->res);
	}
}

int					print_oct(va_list args, t_obj *obj)
{
	unsigned long long	n;
	char				*nbr;

	n = get_num_o(args, obj);
	nbr = ft_lltoa(n);
	if (n == 0)
		nbr = ft_strdup("0");
	else
		nbr = ft_convert_base(nbr, "0123456789", "01234567");
	obj->len = ft_strlen(nbr);
	if (obj->precision > obj->len)
		fill_precision_nbr(obj);
	if (n != 0 || (!obj->dot || obj->precision))
		obj->res = ft_strjoin(obj->res, nbr);
	if (n == 0)
		obj->prefix = 0;
	process_width_o(obj);
	ft_putstr_fd(obj->res, 1);
	obj->return_value += ft_strlen(obj->res);
	free(nbr);
	return (1);
}
