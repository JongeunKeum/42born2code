/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:51:46 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/22 15:08:56 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_percent(t_obj *obj)
{
	char	*per;

	per = ft_strdup("%");
	obj->res = ft_strjoin(per, obj->res);
	obj->len = ft_strlen(obj->res);
	if (obj->width > obj->len)
		fill_width(obj);
	ft_putstr_fd(obj->res, 1);
	obj->return_value += ft_strlen(obj->res);
	free(per);
	return (1);
}

int	print_address(va_list args, t_obj *obj)
{
	unsigned long long	n;
	char				*adr;

	n = (unsigned long long)va_arg(args, void *);
	adr = ft_ptoa(n);
	obj->len = ft_strlen(adr);
	obj->prefix = 2;
	if (obj->precision > obj->len)
		fill_precision_nbr(obj);
	if ((!obj->dot || obj->precision) || n != 0)
		obj->res = ft_strjoin(obj->res, adr);
	if (obj->width > (int)ft_strlen(obj->res) + obj->prefix)
		fill_width(obj);
	else
	{
		if (obj->prefix)
			obj->res = ft_strjoin("0x", obj->res);
	}
	ft_putstr_fd(obj->res, 1);
	obj->return_value += ft_strlen(obj->res);
	free(adr);
	return (1);
}
