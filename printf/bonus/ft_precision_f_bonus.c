/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_f_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:15:46 by jkeum             #+#    #+#             */
/*   Updated: 2020/12/09 23:27:38 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_includes/ft_printf_bonus.h"

static int	chk_all_zero(t_obj *obj)
{
	int	i;

	i = obj->precision;
	while (++i < 1074)
	{
		if (obj->fobj.deci_res[i])
			break ;
	}
	if (i == 1074)
		return (1);
	return (0);
}

static void	arr_int_to_char(t_obj *obj)
{
	int	i;

	i = obj->precision;
	while (--i >= 0)
		obj->fobj.deci_res[i] += '0';
	obj->fobj.deci_res[obj->precision] = 0;
	if (obj->fobj.inte_len == 0)
		obj->fobj.inte_len++;
	i = 308 - obj->fobj.inte_len;
	while (++i < 309)
		obj->fobj.inte_res[i] += '0';
}

static void	deci_res_precision(t_obj *obj, int idx)
{
	int	inte_idx;

	inte_idx = 308;
	if (idx >= 0)
	{
		while (idx >= 0 && obj->fobj.deci_res[idx] >= 10)
		{
			obj->fobj.deci_res[idx--] %= 10;
			if (idx >= 0)
				obj->fobj.deci_res[idx]++;
			else
				obj->fobj.inte_res[inte_idx]++;
		}
	}
	if (idx < 0)
	{
		while (obj->fobj.inte_res[inte_idx] >= 10)
		{
			obj->fobj.inte_res[inte_idx--] %= 10;
			obj->fobj.inte_res[inte_idx]++;
		}
		if (309 - inte_idx > obj->fobj.inte_len)
			obj->fobj.inte_len++;
	}
	arr_int_to_char(obj);
}

void		cut_precision_f(t_obj *obj)
{
	int	idx;

	if (!obj->dot)
		obj->precision = 6;
	idx = obj->precision - 1;
	if (obj->fobj.deci_res[obj->precision] == 5 && chk_all_zero(obj))
	{
		if (obj->precision > 0 && obj->fobj.deci_res[obj->precision - 1] % 2 == 1)
			obj->fobj.deci_res[idx]++;
		else if (!obj->precision && obj->fobj.inte_res[308] % 2 == 1)
			obj->fobj.inte_res[308]++;
	}
	else if (obj->fobj.deci_res[obj->precision] >= 5)
	{
		if (obj->precision > 0)
			obj->fobj.deci_res[idx]++;
		else
			obj->fobj.inte_res[308]++;
	}
	deci_res_precision(obj, idx);
}