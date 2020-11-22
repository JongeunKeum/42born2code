/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:35:04 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/22 15:32:53 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	fill_precision_nbr(t_obj *obj)
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

void	fill_width(t_obj *obj)
{
	int		len;
	int		prev_len;
	int		flag;
	char	*wid;

	prev_len = ft_strlen(obj->res);
	len = obj->width - prev_len;
	flag = obj->neg | obj->space | obj->sign;
	if (obj->prefix == 1 && obj->dot)
		obj->prefix = 0;
	if (obj->left)
	{
		wid = (char *)calloc(len + 1, 1);
		if (obj->space)
			obj->res = ft_strjoin(" ", obj->res);
		else if (obj->sign)
			obj->res = ft_strjoin("+", obj->res);
		else if (obj->neg)
			obj->res = ft_strjoin("-", obj->res);
		else if (obj->prefix == 2)
			obj->res = ft_strjoin("0x", obj->res);
		else if (obj->prefix == 1)
			obj->res = ft_strjoin("0", obj->res);
		wid = ft_memset(wid + flag + obj->prefix, ' ', len - flag - obj->prefix);
		obj->res = ft_strjoin(obj->res, wid);
		free(wid - flag - obj->prefix);
	}
	else
	{
		wid = (char *)calloc(obj->width + 1, 1);
		if (!obj->dot && obj->zero)
		{
			if (obj->space)
				wid[0] = ' ';
			else if (obj->sign)
				wid[0] = '+';
			else if (obj->neg)
				wid[0] = '-';
			ft_memset(wid + flag, '0', len - flag);
			if (obj->prefix == 2)
				wid[1] = 'x';
			obj->res = ft_strjoin(wid, obj->res);
			free(wid);
		}
		else
		{
			wid = ft_memset(wid, ' ', len - flag - obj->prefix);
			if (obj->space)
				wid[len - flag] = ' ';
			else if (obj->sign)
				wid[len - flag] = '+';
			else if (obj->neg)
				wid[len - flag] = '-';
			else if (obj->prefix == 2)
			{
				wid[len - flag - obj->prefix] = '0';
				wid[len - flag - obj->prefix + 1] = 'x';
			}
			else if (obj->prefix == 1)
				wid[len - flag - obj->prefix] = '0';
			wid[len] = '\0';
			obj->res = ft_strjoin(wid, obj->res);
			free(wid);
		}
	}
}

int		print_int(va_list args, t_obj *obj)
{
	long long	n;
	char		*nbr;

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
