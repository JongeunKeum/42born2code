/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chk_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 10:59:25 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/29 17:08:23 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	check_width(const char *str, t_obj *obj, va_list args)
{
	obj->width = 0;
	if (str[obj->idx] > '0' && str[obj->idx] <= '9')
	{
		while (ft_isdigit(str[obj->idx]))
			obj->width = obj->width * 10 + (str[obj->idx++] - '0');
	}
	else if (str[obj->idx] == '*')
	{
		obj->width = va_arg(args, int);
		if (obj->width < 0)
		{
			obj->width *= -1;
			obj->left = 1;
		}
		obj->idx++;
	}
}

static void	check_precision(const char *str, t_obj *obj, va_list args)
{
	obj->precision = 0;
	obj->dot = 1;
	obj->idx++;
	if (ft_isdigit(str[obj->idx]))
	{
		while (ft_isdigit(str[obj->idx]))
			obj->precision = obj->precision * 10 + (str[obj->idx++] - '0');
	}
	else if (str[obj->idx] == '*')
	{
		obj->precision = va_arg(args, int);
		obj->idx++;
	}
	if (obj->precision < 0)
		obj->dot = 0;
}

static void	check_flag(const char *str, t_obj *obj)
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
		obj->prefix = 2;
}

static int	check_type(va_list args, t_obj *obj)
{
	if (obj->type == 'd' || obj->type == 'i')
		return (print_int(args, obj));
	else if (obj->type == 'c')
		return (print_char(args, obj));
	else if (obj->type == 's')
		return (print_str(args, obj));
	else if (obj->type == 'u')
		return (print_unsigned_int(args, obj));
	else if (obj->type == 'x' || obj->type == 'X')
		return (print_hex(args, obj));
	else if (obj->type == 'o')
		return (print_oct(args, obj));
	else if (obj->type == 'p')
		return (print_address(args, obj));
	else if (obj->type == '%')
		return (print_percent(obj));
	else if (obj->type == 'n')
		return (print_num_ch(args, obj));
	else
		return (0);
}

int			check_format(const char *str, va_list args, t_obj *obj)
{
	obj->idx++;
	while (!ft_strchr("cdisupxXon%", str[obj->idx]))
	{
		while (ft_strchr("-0 #+", str[obj->idx]))
		{
			check_flag(str, obj);
			obj->idx++;
		}
		check_width(str, obj, args);
		if (str[obj->idx] == '.')
			check_precision(str, obj, args);
		check_length(str, obj);
	}
	obj->type = str[obj->idx];
	if (obj->type == 'o' && obj->prefix)
		obj->prefix = 1;
	if (!(check_type(args, obj)))
		return (0);
	return (1);
}
