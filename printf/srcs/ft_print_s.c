/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 14:58:56 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/29 14:27:33 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_str(va_list args, t_obj *obj)
{
	char	*s;
	char	*null;

	s = va_arg(args, char *);
	if (!(null = ft_strdup("(null)")))
		return (0);
	if (!s)
		s = null;
	obj->len = ft_strlen(s);
	if (obj->dot && obj->precision < obj->len)
	{
		if (!(obj->res = ft_substr(s, 0, obj->precision)))
		{
			free(null);
			return (0);
		}
	}
	else
	{
		if (!(obj->res = ft_strjoin_free(obj->res, s, 1)))
		{
			free(null);
			return (0);
		}
	}
	free(null);
	if (obj->width > (int)ft_strlen(obj->res))
	{
		if (!(fill_width(obj)))
			return (0);
	}
	ft_putstr_fd(obj->res, 1);
	obj->return_value += ft_strlen(obj->res);
	return (1);
}
