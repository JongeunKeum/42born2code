/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:35:04 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/06 21:41:42 by jkeum            ###   ########.fr       */
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
		len = obj->precision - obj->len + 2 * obj->neg;
		res = (char *)malloc(len + 1);
		if (obj->neg == 1)
			res[0] = '-';
		i = obj->neg;
		while (i < len)
			res[i++] = '0';
		res[len] = '\0';
		res = ft_strjoin(prev, res);
	}
	else
	{
		if (obj->neg)
			res = ft_strjoin(prev, ft_strdup("-"));
		else
			res = prev;
	}
	return (res);
}

char	*fill_width(t_obj *obj, char *prev)
{
	int		i;
	int		len;
	char	*res;

	len = obj->width - ft_strlen(prev);
	res = (char *)malloc(len +  1);
	i = 0;
	while (i < len)
		res[i++] = ' ';
	res[len] = '\0';
	if (obj->left)
		res = ft_strjoin(prev, res);
	else
		res = ft_strjoin(res, prev);
	return (res);
}

int		print_int(va_list args, t_obj *obj)
{
	int		n;
	char	*nbr;
	char	*res;

	n = va_arg(args, int);
	if (n < 0)
		obj->neg = 1;
	nbr = ft_itoa(n);
	obj->len = ft_strlen(nbr);
	res = ft_strdup("");
	if (obj->precision > 0)
		res = fill_precision(obj, res);
	if (obj->neg && obj->precision > 0)
		res = ft_strjoin(res, nbr + 1);
	else
		res = ft_strjoin(res, nbr);
	if (obj->width > (int)ft_strlen(res))
		res = fill_width(obj, res);
	ft_putstr_fd(res, 1);
	free(res);
	return (1);
}
