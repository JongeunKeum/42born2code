/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:35:04 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/09 15:09:50 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*fill_precision(t_obj *obj, char *prev)
{
	int		i;
	int		len;
	char	*res;

	if (obj->precision > obj->len)
	{
		len = obj->precision - obj->len + obj->neg;
		res = (char *)malloc(len + 1);
		i = 0;
		while (i < len)
			res[i++] = '0';
		res[len] = '\0';
		res = ft_strjoin(prev, res);
	}
	else
		res = prev;
	return (res);
}

char	*fill_width(t_obj *obj, char *prev)
{
	int		len;
	int		prev_len;
	int		flag;
	char	*res;

	prev_len = ft_strlen(prev);
	len = obj->width - prev_len;
	flag = obj->neg | obj->space | obj->sign;
	if (obj->left)
	{
		res = (char *)malloc(len + 1);
		if (obj->space)
			prev = ft_strjoin(" ", prev);
		else if (obj->sign)
			prev = ft_strjoin("+", prev);
		else if (obj->neg)
			prev = ft_strjoin("-", prev);
		res = ft_memset(res + flag, ' ', len - flag);
		res[len] = '\0';
		return (ft_strjoin(prev, res));
	}
	else
	{
		res = (char *)malloc(obj->width + 1);
		if (!obj->dot && obj->zero)
		{
			if (obj->space)
				res[0] = ' ';
			else if (obj->sign)
				res[0] = '+';
			else if (obj->neg)
				res[0] = '-';
			res = ft_memset(res + flag, '0', len - flag);
			res[len - flag] = '\0';
			return (ft_strjoin(res - flag, prev));
		}
		else
		{
			res = ft_memset(res, ' ', len - obj->neg);
			if (obj->space)
				res[len - flag] = ' ';
			else if (obj->sign)
				res[len - flag] = '+';
			else if (obj->neg)
				res[len - flag] = '-';
			res[len] = '\0';
			return (ft_strjoin(res, prev));
		}
	}
}

int		print_int(va_list args, t_obj *obj)
{
	int		n;
	char	*nbr;
	char	*res;

	n = va_arg(args, int);
	if (n < 0)
		obj->neg = 1;
	if (obj->neg || obj->sign)
		obj->space = 0;
	if (obj->neg)
		obj->sign = 0;
	nbr = ft_lltoa(n);
	obj->len = ft_strlen(nbr);
	res = ft_strdup("");
	if (obj->precision > obj->len)
		res = fill_precision(obj, res);
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
		else if (obj->neg)
			res = ft_strjoin("-", res);
	}
	ft_putstr_fd(res, 1);
	obj->return_value += ft_strlen(res);
	free(res);
	return (1);
}
