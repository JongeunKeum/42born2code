/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_inte.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 19:57:26 by jkeum             #+#    #+#             */
/*   Updated: 2020/12/06 18:15:16 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	process_inte_bin(t_obj *obj, t_fpoint *fp)
{
	int				i;
	int				start_idx;
	int				range;
	unsigned long	temp;

	if (obj->fobj.expnt >= 0)
	{
		range = (obj->fobj.expnt > 52) ? 52 : obj->fobj.expnt;
		temp = fp->bitfield.mantissa >> (52 - range);
		start_idx = 1024 - obj->fobj.expnt - 1;
		obj->fobj.inte_bin[start_idx] = 1;
		i = 0;
		while (start_idx < 1024 && range >= i)
		{
			if ((temp >> (range - i++)) & 1)
				obj->fobj.inte_bin[start_idx] = 1;
			start_idx++;
		}
	}
}

void	process_inte_two(t_obj *obj)
{
	int	rounding;
	int	res;
	int	i;
	int	j;

	rounding = 0;
	i = -1;
	j = obj->fobj.two;
	while (++i <= j)
	{
		res = obj->fobj.inte_two[i] * 2;
		obj->fobj.inte_two[i] = res % 10 + rounding;
		rounding = res / 10;
		if (rounding > 0 && i + 1 > j)
		{
			obj->fobj.inte_two[i + 1] = rounding;
			obj->fobj.two++;
		}
	}
	obj->fobj.inte_two[i] = rounding;
}

void	process_inte_res(t_obj *obj)
{
	int	i;
	int	j;

	i = -1;
	j = obj->fobj.two;
	while (++i <= j)
	{
		obj->fobj.inte_res[i] += (obj->fobj.inte_two[i] + obj->fobj.rounding);
		if (obj->fobj.inte_res[i] >= 10)
		{
			obj->fobj.rounding = obj->fobj.inte_res[i] / 10;
			obj->fobj.inte_res[i] %= 10;
			if (i + 1 > j)
				j++;
		}
		else
			obj->fobj.rounding = 0;
	}
}

void	ft_strrev_f(t_obj *obj)
{
	int		i;
	int		len;
	char	temp;

	i = -1;
	len = 309;
	while (++i < --len)
	{
		temp = obj->fobj.inte_res[i];
		obj->fobj.inte_res[i] = obj->fobj.inte_res[len];
		obj->fobj.inte_res[len] = temp;
	}
}
