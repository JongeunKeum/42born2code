/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:51:46 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/26 17:58:10 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_percent(t_obj *obj)
{
	char	*per;

	if (!(per = ft_strdup("%")))
		return (0);
	if (!(obj->res = ft_strjoin(per, obj->res)))
	{
		free(per);
		return (0);
	}
	free(per);
	obj->len = ft_strlen(obj->res);
	if (obj->width > obj->len)
	{
		if (!(fill_width(obj)))
			return (0);
	}
	ft_putstr_fd(obj->res, 1);
	obj->return_value += ft_strlen(obj->res);
	return (1);
}

int	print_address(va_list args, t_obj *obj)
{
	unsigned long long	n;
	char				*adr;

	n = (unsigned long long)va_arg(args, void *);
	if (!(adr = ft_ptoa(n)))
		return (0);
	obj->len = ft_strlen(adr);
	obj->prefix = 2;
	if (obj->precision > obj->len)
	{
		if (!(fill_precision_nbr(obj)))
		{
			free(adr);
			return (0);
		}
	}
	if ((!obj->dot || obj->precision) || n != 0)
	{
		if (!(obj->res = ft_strjoin(obj->res, adr)))
		{
			free(adr);
			return (0);
		}
	}
	free(adr);
	if (obj->width > (int)ft_strlen(obj->res) + obj->prefix)
	{
		if (!(fill_width(obj)))
			return (0);
	}
	else
	{
		if (obj->prefix)
		{
			if (!(obj->res = ft_strjoin("0x", obj->res)))
				return (0);
		}
	}
	ft_putstr_fd(obj->res, 1);
	obj->return_value += ft_strlen(obj->res);
	return (1);
}
