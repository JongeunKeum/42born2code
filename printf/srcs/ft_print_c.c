/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:10:09 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/25 21:44:23 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	fill_width_null(t_obj *obj, char c)
{
	int		len;
	char	*wid;

	len = obj->width - 1;
	if (!(wid = (char *)ft_calloc(len + 1, 1)))
		return ;
	wid = ft_memset(wid, ' ', len);
	if (!(obj->res = ft_strjoin(wid, obj->res)))
	{
		free(wid);
		return ;
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
}

void	is_not_null_c(t_obj *obj, char c)
{
	char	*ch;

	if (!(ch = (char *)ft_calloc(2, 1)))
		return ;
	ch[0] = c;
	if (!(obj->res = ft_strjoin(obj->res, ch)))
	{
		free(ch);
		return ;
	}
	if (obj->width > (int)ft_strlen(obj->res))
		fill_width(obj);
	ft_putstr_fd(obj->res, 1);
	obj->return_value += ft_strlen(obj->res);
	free(ch);
}

int		print_char(va_list args, t_obj *obj)
{
	char	c;

	c = (char)va_arg(args, int);
	if (c != '\0')
		is_not_null_c(obj, c);
	else
	{
		if (obj->width > 1)
		{
			fill_width_null(obj, c);
			obj->return_value += ft_strlen(obj->res) + 1;
		}
		else
		{
			ft_putchar_fd(c, 1);
			obj->return_value += 1;
		}
	}
	return (1);
}
