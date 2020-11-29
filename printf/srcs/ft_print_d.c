/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:35:04 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/29 13:45:09 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int			fill_precision_nbr(t_obj *obj)
{
	int		i;
	int		len;
	char	*prec;

	len = obj->precision - obj->len + obj->neg;
	if (!(prec = (char *)ft_calloc(len + 1, 1)))
		return (0);
	i = 0;
	while (i < len)
		prec[i++] = '0';
	if (!(obj->res = ft_strjoin_free(obj->res, prec, 1)))
	{
		free(prec);
		return (0);
	}
	free(prec);
	return (1);
}

long long	get_num_d(va_list args, t_obj *obj)
{
	long long	n;

	if (obj->length == 3)
		n = va_arg(args, long);
	else if (obj->length == 4)
		n = va_arg(args, long long);
	else if (obj->length == 2)
		n = (char)va_arg(args, int);
	else if (obj->length == 1)
		n = (short)va_arg(args, int);
	else
		n = va_arg(args, int);
	if (n < 0)
		obj->neg = 1;
	if (obj->neg || obj->sign)
		obj->space = 0;
	if (obj->neg)
		obj->sign = 0;
	return (n);
}

int			print_int(va_list args, t_obj *obj)
{
	long long	n;
	char		*nbr;

	n = get_num_d(args, obj);
	if (!(nbr = ft_lltoa(n)))
		return (0);
	obj->len = ft_strlen(nbr);
	if (obj->precision > obj->len - obj->neg)
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
	free(nbr);
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
		else if (obj->neg)
			obj->res = ft_strjoin_free("-", obj->res, 2);
		if (!obj->res)
			return (0);
	}
	ft_putstr_fd(obj->res, 1);
	obj->return_value += ft_strlen(obj->res);
	return (1);
}
