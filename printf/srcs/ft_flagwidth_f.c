/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagwidth_f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 17:46:10 by jkeum             #+#    #+#             */
/*   Updated: 2020/12/09 23:48:27 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	is_zeroflag_f(t_obj *obj, int range)
{
	int	i;

	i = 0;
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

static void	no_zero_n_left_f(t_obj *obj, int range)
{
	int	i;

	i = 0;
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

static void	is_leftflag_f(t_obj *obj, int range)
{
	int	i;

	i = 0;
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

static void	print_flag_n_width(t_obj *obj, int total_len)
{
	int	range;

	range = obj->width - total_len;
	if (obj->left)
		is_leftflag_f(obj, range);
	else
	{
		if (obj->zero)
			is_zeroflag_f(obj, range);
		else
			no_zero_n_left_f(obj, range);
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
	print_flag_n_width(obj, total_len);
}
