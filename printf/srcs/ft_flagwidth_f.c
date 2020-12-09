/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagwidth_f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 17:46:10 by jkeum             #+#    #+#             */
/*   Updated: 2020/12/09 23:34:54 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	print_out_result(t_obj *obj)
{
	int	i;

	i = 309 - obj->fobj.inte_len;
	while (i < 309)
	{
		ft_putchar_fd(obj->fobj.inte_res[i], 1);
		obj->return_value++;
		i++;
	}
	if (obj->precision || obj->prefix)
	{
		write(1, ".", 1);
		obj->return_value++;
	}
	i = -1;
	while (obj->fobj.deci_res[++i])
		ft_putchar_fd(obj->fobj.deci_res[i], 1);
	obj->return_value += i;
}

static void	is_zeroflag_f(t_obj *obj, int range)
{
	int	i;

	i = 0;
	if (obj->zero)
	{
		if (obj->neg)
		{
			write(1, "-", 1);
			obj->return_value++;
		}
		if (obj->sign && !obj->neg)
		{
			write(1, "+", 1);
			obj->return_value++;
		}
		while (i++ < range)
			write(1, "0", 1);
		obj->return_value += (i - 1);
	}
	else
	{
		while (i++ < range)
			write(1, " ", 1);
		obj->return_value += (i - 1);
		if (obj->neg)
		{
			write(1, "-", 1);
			obj->return_value++;
		}
		if (obj->sign && !obj->neg)
		{
			write(1, "+", 1);
			obj->return_value++;
		}
	}
}

static void	chk_leftflag_f(t_obj *obj, int total_len)
{
	int	range;
	int	i;

	i = 0;
	range = obj->width - total_len;
	if (obj->left)
	{
		if (obj->neg)
		{
			write(1, "-", 1);
			obj->return_value++;
		}
		if (obj->sign && !obj->neg)
		{
			write(1, "+", 1);
			obj->return_value++;
		}
		print_out_result(obj);
		while (i++ < range)
			write(1, " ", 1);
		obj->return_value += (i - 1);
	}
	else
	{
		is_zeroflag_f(obj, range);
		print_out_result(obj);
	}
}

void		flag_n_width_f(t_obj *obj)
{
	int	deci_len;
	int	total_len;

	deci_len = ft_strlen(obj->fobj.deci_res);
	if (obj->precision || obj->prefix)
		deci_len++;
	total_len = obj->fobj.inte_len + deci_len + obj->neg;
	if (obj->sign && !obj->neg)
		total_len++;
	if (obj->space && !obj->sign && !obj->neg)
	{
		write(1, " ", 1);
		total_len++;
		obj->return_value++;
	}
	chk_leftflag_f(obj, total_len);
}
