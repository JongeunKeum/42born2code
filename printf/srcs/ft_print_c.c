/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:10:09 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/29 16:58:08 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	fill_width_null(t_obj *obj, char c)
{
	int		len;
	char	*wid;

	len = obj->width - 1;
	if (!(wid = (char *)ft_calloc(len + 1, 1)))
		return (0);
	wid = ft_memset(wid, ' ', len);
	if (!(obj->res = ft_strjoin_free(wid, obj->res, 2)))
	{
		free(wid);
		return (0);
	}
	if (obj->left)
	{
		ft_putchar_fd(c, 1);
		ft_putstr_fd(obj->res, 1);
	}
	else
	{
		ft_putstr_fd(obj->res, 1);
		ft_putchar_fd(c, 1);
	}
	free(wid);
	return (1);
}

static int	is_not_null_c(t_obj *obj, char c)
{
	char	*ch;

	if (!(ch = (char *)ft_calloc(2, 1)))
		return (0);
	ch[0] = c;
	if (!(obj->res = ft_strjoin_free(obj->res, ch, 1)))
	{
		free(ch);
		return (0);
	}
	free(ch);
	if (obj->width > (int)ft_strlen(obj->res))
	{
		if (!(fill_width(obj)))
			return (0);
	}
	ft_putstr_fd(obj->res, 1);
	obj->return_value += ft_strlen(obj->res);
	return (1);
}

int			print_char(va_list args, t_obj *obj)
{
	char	c;

	obj->res = (char *)ft_calloc(1, 1);
	c = (char)va_arg(args, int);
	if (c != '\0')
	{
		if (!(is_not_null_c(obj, c)))
			return (0);
	}
	else
	{
		if (obj->width > 1)
		{
			if (!(fill_width_null(obj, c)))
				return (0);
			obj->return_value += ft_strlen(obj->res) + 1;
		}
		else
		{
			ft_putchar_fd(c, 1);
			obj->return_value += 1;
		}
	}
	free(obj->res);
	return (1);
}
