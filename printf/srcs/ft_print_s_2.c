/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 14:58:56 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/22 14:16:24 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_str(va_list args, t_obj *obj)
{
	char	*s;
	char	*null;

	s = va_arg(args, char *);
	null = ft_strdup("(null)");
	if (!s)
		s = null;
	obj->len = ft_strlen(s);
	if (obj->dot && obj->precision < obj->len)
		obj->res = ft_substr(s, 0, obj->precision);
	else
		obj->res = ft_strjoin(obj->res, s);
	if (obj->width > (int)ft_strlen(obj->res))
		fill_width(obj);
	ft_putstr_fd(obj->res, 1);
	obj->return_value += ft_strlen(obj->res);
	free(null);
	return (1);
}
