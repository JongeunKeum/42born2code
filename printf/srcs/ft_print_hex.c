/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:09:09 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/16 19:33:07 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_hex(va_list args, t_obj *obj)
{
	int					i;
	unsigned int		n;
	char				*nbr;
	char				*res;

	n = va_arg(args, unsigned int);
	nbr = ft_lltoa(n);
	if (n == 0)
		nbr = ft_strdup("0");
	else
		nbr = ft_convert_base(nbr, "0123456789", "0123456789abcdef");
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
		if (obj->prefix)
			res = ft_strjoin("0x", res);
	}
	if (obj->type == 'X') 
	{
		i = -1;
		while (res[++i])
			res[i] = ft_toupper(res[i]);
	}
	ft_putstr_fd(res, 1);
	obj->return_value += ft_strlen(res);
	free(res);
	return (1);
}
