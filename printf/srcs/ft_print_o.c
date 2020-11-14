/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 16:42:37 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/14 17:31:27 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_oct(va_list args, t_obj *obj)
{
	unsigned int	n;
	char			*nbr;
	char			*res;

	n = va_arg(args, unsigned int);
	nbr = ft_lltoa(n);
	if (n == 0)
		nbr = ft_strdup("0");
	else
		nbr = ft_convert_base(nbr, "0123456789", "01234567");
	obj->len = ft_strlen(nbr);
	res = ft_strdup("");
	if (obj->precision > obj->len)
		res = fill_precision_nbr(obj, res);
	if ((!obj->dot || obj->precision) || n != 0)
		res = ft_strjoin(res, nbr);
	if (n == 0)
		obj->prefix = 0;
	if (obj->width > (int)ft_strlen(res) + obj->prefix)
		res = fill_width(obj, res);
	else
	{
		if (obj->prefix && (!obj->dot || !obj->precision))
			res = ft_strjoin("0", res);
	}
	ft_putstr_fd(res, 1);
	obj->return_value += ft_strlen(res);
	return (1);
}
