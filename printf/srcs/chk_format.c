/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_prefix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 10:59:25 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/06 21:41:44 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	check_width(const char *str, t_obj *obj)
{
	obj->width = 0;
	if (str[obj->idx] > '0' && str[obj->idx] <= '9')
	{
		while (ft_isdigit(str[obj->idx]))
			obj->width = obj->width * 10 + (str[obj->idx++] - '0');
	}
}

void	check_precision(const char *str, t_obj *obj)
{
	obj->precision = 0;
	obj->idx++;
	if (ft_isdigit(str[obj->idx]))
	{
		while (ft_isdigit(str[obj->idx]))
			obj->precision = obj->precision * 10 + (str[obj->idx++] - '0');
	}
}

void	check_flag(const char *str, t_obj *obj)
{
	if (str[obj->idx] == '-')
		obj->left = 1;
	if (str[obj->idx] == '0')
		obj->zero = 1;
	if (str[obj->idx] == '+')
		obj->sign = 1;
	if (str[obj->idx] == ' ')
		obj->space = 1;
	if (str[obj->idx] == '#')
		obj->prefix = 1;
}

int		check_type(va_list args, t_obj *obj)
{
	if (obj->type == 'd')
		return (print_int(args, obj));
/*	else if (obj->type == 'c')
		print_char(str, args, obj);
	else if (obj->type == 's')
		print_str(str, args, obj);
	else if (obj->type == 'u')
		print_unsigned(str, args, obj);
	else if (obj->type == 'p')
		print_address(str, args, obj);
	else if (obj->type == 'x')
		print_hex_lower(str, args, obj);
	else if (obj->type == 'X')
		print_hex_upper(str, args, obj);
		*/
	else
		return (0);
}

int		check_format(const char *str, va_list args, t_obj *obj)
{
	obj->idx++;
	while (!ft_strchr("cdisupxX", str[obj->idx]))
	{
		while (ft_strchr("-0 #+", str[obj->idx]))
		{
			check_flag(str, obj);
			obj->idx++;
		}
		check_width(str, obj);
		if (str[obj->idx] == '.')
			check_precision(str, obj);
	}
	obj->type = str[obj->idx];
	if (check_type(args, obj))
		return (1);
	return (0);
}
