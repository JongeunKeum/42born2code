/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:51:46 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/18 19:27:19 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_percent(t_obj *obj)
{
	char	*res;

	res = ft_strdup("%");
	obj->len = ft_strlen(res);
	if (obj->width > obj->len)
		res = fill_width(obj, res);
	ft_putstr_fd(res, 1);
	obj->return_value += ft_strlen(res);
	free(res);
	return (1);
}

int	print_address(va_list args, t_obj *obj)
{
	unsigned long long	n;
	char				*adr;
	char				*res;

	n = (unsigned long long)va_arg(args, void *);
	adr = ft_ptoa(n);
	obj->len = ft_strlen(adr);
	obj->prefix = 2;
	res = ft_strdup("");
	if (obj->precision > obj->len)
		res = fill_precision_nbr(obj, res);
	if ((!obj->dot || obj->precision) || n != 0)
		res = ft_strjoin(res, adr);
	if (obj->width > (int)ft_strlen(res) + obj->prefix)
		res = fill_width(obj, res);
	else
	{
		if (obj->prefix)
			res = ft_strjoin("0x", res);
	}
	ft_putstr_fd(res, 1);
	obj->return_value += ft_strlen(res);
	free(adr);
	free(res);
	return (1);
}
