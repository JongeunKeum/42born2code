/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:09:09 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/26 17:43:06 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

unsigned long long	get_num_x(va_list args, t_obj *obj)
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

void				is_type_upper(t_obj *obj)
{
	int	i;

	i = -1;
	while (obj->res[++i])
		obj->res[i] = ft_toupper(obj->res[i]);
}

int					process_width_x(t_obj *obj)
{
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
	return (1);
}

int					print_hex(va_list args, t_obj *obj)
{
	unsigned long long	n;
	char				*nbr;

	n = get_num_x(args, obj);
	if (!(nbr = ft_lltoa(n)))
		return (0);
	if (n == 0)
	{
		free(nbr);
		if (!(nbr = ft_strdup("0")))
			return (0);
	}
	else
	{
		if (!(nbr = ft_convert_base(nbr, "0123456789", "0123456789abcdef")))
		{
			free(nbr);
			return (0);
		}
	}
	obj->len = ft_strlen(nbr);
	if (obj->precision > obj->len)
	{
		if (!(fill_precision_nbr(obj)))
		{
			free(nbr);
			return (0);
		}
	}
	if (n != 0 || (!obj->dot || obj->precision))
	{
		if (!(obj->res = ft_strjoin(obj->res, nbr)))
		{
			free(nbr);
			return (0);
		}
	}
	free(nbr);
	if (n == 0)
		obj->prefix = 0;
	if (!(process_width_x(obj)))
		return (0);
	if (obj->type == 'X')
		is_type_upper(obj);
	ft_putstr_fd(obj->res, 1);
	obj->return_value += ft_strlen(obj->res);
	return (1);
}
