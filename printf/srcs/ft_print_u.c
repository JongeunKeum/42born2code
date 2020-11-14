/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:13:22 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/12 15:39:21 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_unsigned_int(va_list args, t_obj *obj)
{
	unsigned int	n;
	char			*nbr;
	char			*res;

	n = va_arg(args, unsigned int);
	if (obj->sign)
		obj->space = 0;
	nbr = ft_lltoa(n);
	obj->len = ft_strlen(nbr);
	res = ft_strdup("");
	if (obj->precision > obj->len)
		res = fill_precision_nbr(obj, res);
	if (!obj->dot || obj->precision)
		res = ft_strjoin(res, nbr + obj->neg);
	if (obj->width > (int)ft_strlen(res))
		res = fill_width(obj, res);
	else
	{
		if (obj->space)
			res = ft_strjoin(" ", res);
		else if (obj->sign)
			res = ft_strjoin("+", res);
	}
	ft_putstr_fd(res, 1);
	obj->return_value += ft_strlen(res);
	free(res);
	return (1);
}
