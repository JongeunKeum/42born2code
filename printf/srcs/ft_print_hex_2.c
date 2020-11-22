/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:09:09 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/22 14:42:21 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_hex(va_list args, t_obj *obj)
{
	int					i;
	unsigned long long	n;
	char				*nbr;

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
	nbr = ft_lltoa(n);
	if (n == 0)
		nbr = ft_strdup("0");
	else
		nbr = ft_convert_base(nbr, "0123456789", "0123456789abcdef");
	obj->len = ft_strlen(nbr);
	if (obj->precision > obj->len)
		fill_precision_nbr(obj);
	if ((!obj->dot || obj->precision) || n != 0)
		obj->res = ft_strjoin(obj->res, nbr); 
	if (n == 0)
		obj->prefix = 0;
	if (obj->width > (int)ft_strlen(obj->res) + obj->prefix)
		fill_width(obj);
	else
	{
		if (obj->prefix)
			obj->res = ft_strjoin("0x", obj->res);
	}
	if (obj->type == 'X') 
	{
		i = -1;
		while (obj->res[++i])
			obj->res[i] = ft_toupper(obj->res[i]);
	}
	ft_putstr_fd(obj->res, 1);
	obj->return_value += ft_strlen(obj->res);
	free(nbr);
	return (1);
}
