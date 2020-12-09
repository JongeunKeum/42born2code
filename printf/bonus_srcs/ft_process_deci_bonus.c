/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_deci_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 19:21:46 by jkeum             #+#    #+#             */
/*   Updated: 2020/12/09 23:28:26 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_includes/ft_printf_bonus.h"

void	process_deci_bin(t_obj *obj, t_fpoint *fp)
{
	int				i;
	int				j;
	unsigned long	temp;

	if (obj->fobj.expnt >= 0)
	{
		temp = fp->bitfield.mantissa << obj->fobj.expnt;
		i = -1;
		while (++i < 52)
		{
			if ((temp >> (51 - i)) & 1)
				obj->fobj.deci_bin[i] = 1;
		}
	}
	else
	{
		i = obj->fobj.expnt * (-1) - 1;
		obj->fobj.deci_bin[i] = 1;
		j = obj->fobj.expnt * -1;
		while (++i < 52 + j)
		{
			if ((fp->bitfield.mantissa >> (51 - i + j)) & 1)
				obj->fobj.deci_bin[i] = 1;
		}
	}
}

void	process_deci_five(t_obj *obj, int idx)
{
	int	rounding;
	int	i;
	int	res;

	rounding = 0;
	i = idx + 1;
	while (--i > 0)
	{
		res = obj->fobj.deci_five[i - 1] * 5;
		obj->fobj.deci_five[i] = res % 10 + rounding;
		rounding = res / 10;
	}
	obj->fobj.deci_five[0] = rounding;
}

void	process_deci_res(t_obj *obj, int idx)
{
	int	i;

	i = idx + 1;
	while (--i >= 0)
	{
		obj->fobj.deci_res[i] += (obj->fobj.deci_five[i] + obj->fobj.rounding);
		if (obj->fobj.deci_res[i] >= 10)
		{
			obj->fobj.rounding = 1;
			obj->fobj.deci_res[i] %= 10;
		}
		else
			obj->fobj.rounding = 0;
	}
}
