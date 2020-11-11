/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 14:58:56 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/11 15:44:26 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_str(va_list args, t_obj *obj)
{
	char	*s;
	char	*res;

	s = va_arg(args, char *);
	if (!s)
		s = ft_strdup("(null)");
	else
		res = ft_strdup("");
	obj->len = ft_strlen(s);
	if (obj->dot && obj->precision < obj->len)
		res = ft_substr(s, 0, obj->precision);
	else
		res = ft_strjoin(res, s);
	if (obj->width > (int)ft_strlen(res))
		res = fill_width(obj, res);
	ft_putstr_fd(res, 1);
	obj->return_value += ft_strlen(res);
	return (1);
}
