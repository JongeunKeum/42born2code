/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:10:09 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/10 21:27:29 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*fill_width_null(t_obj *obj, char c)
{
	int		len;
	char	*res;

	len = obj->width - 1;
	res = (char *)calloc(len + 1, 1);
	res = ft_memset(res, ' ', len);
	if (obj->left)
	{
		ft_putchar_fd(c, 1);
		ft_putstr_fd(res, 1);
	}
	else
	{
		ft_putstr_fd(res, 1);
		ft_putchar_fd(c, 1);
	}
	return (res);
}

int		print_char(va_list args, t_obj *obj)
{
	char	c;
	char	*res;

	c = (char)va_arg(args, int);
	if (c != '\0')
	{
		res = (char *)calloc(2, sizeof(char));
		res[0] = c;
		if (obj->width > (int)ft_strlen(res))
			res = fill_width(obj, res);
		ft_putstr_fd(res, 1);
		obj->return_value += ft_strlen(res);
	}
	else
	{
		res = ft_strdup("");
		if (obj->width > 1)
			res = fill_width_null(obj, c);
		else
			ft_putchar_fd(c, 1);
		obj->return_value += ft_strlen(res) + 1;
	}
	free(res);
	return (1);
}
