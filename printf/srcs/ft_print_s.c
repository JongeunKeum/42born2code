/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 14:58:56 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/29 17:04:46 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		process_precision_s(char *s, t_obj *obj)
{
	if (obj->dot && obj->precision < obj->len)
	{
		if (!(obj->res = ft_substr(s, 0, obj->precision)))
			return (0);
	}
	else
	{
		if (!(obj->res = ft_strdup(s)))
			return (0);
	}
	return (1);
}

int				print_str(va_list args, t_obj *obj)
{
	char	*s;
	char	*null;

	s = va_arg(args, char *);
	if (!(null = ft_strdup("(null)")))
		return (0);
	if (!s)
		s = null;
	obj->len = ft_strlen(s);
	if (!(process_precision_s(s, obj)))
	{
		free(null);
		return (0);
	}
	free(null);
	if (obj->width > (int)ft_strlen(obj->res))
	{
		if (!(fill_width(obj)))
			return (0);
	}
	ft_putstr_fd(obj->res, 1);
	obj->return_value += ft_strlen(obj->res);
	free(obj->res);
	return (1);
}
