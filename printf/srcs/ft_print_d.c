/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:35:04 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/23 13:24:05 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		fill_precision_nbr(t_obj *obj)
{
	int		i;
	int		len;
	char	*prec;

	len = obj->precision - obj->len + obj->neg;
	prec = (char *)calloc(len + 1, 1);
	i = 0;
	while (i < len)
		prec[i++] = '0';
	obj->res = ft_strjoin(obj->res, prec);
	free(prec);
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
	nbr = ft_lltoa(n);
	obj->len = ft_strlen(nbr);
	if (obj->precision > obj->len - obj->neg)
		fill_precision_nbr(obj);
	if (n != 0 || (!obj->dot || obj->precision))
		obj->res = ft_strjoin(obj->res, nbr + obj->neg);
	if (obj->width > (int)ft_strlen(obj->res))
		fill_width(obj);
	else
	{
		if (obj->space)
			obj->res = ft_strjoin(" ", obj->res);
		else if (obj->sign)
			obj->res = ft_strjoin("+", obj->res);
		else if (obj->neg)
			obj->res = ft_strjoin("-", obj->res);
	}
	ft_putstr_fd(obj->res, 1);
	obj->return_value += ft_strlen(obj->res);
	free(nbr);
	return (1);
}
