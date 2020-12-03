/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:40:30 by jkeum             #+#    #+#             */
/*   Updated: 2020/12/03 21:57:44 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

static t_fpoint	*init_fobjs(void)
{
	t_fpoint	*fp;

	if (!(fp = (t_fpoint *)malloc(sizeof(t_fpoint))))
		return (NULL);
	fp->bitfield.mantissa = 0;
	fp->bitfield.exponent = 0;
	fp->bitfield.sign = 0;
	fp->realnum = 0;
	return (fp);
}

static void		process_deci_bin(t_obj *obj, t_fpoint *fp)
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

static void		process_deci_five(t_obj *obj, int idx)
{
	int	rounding;
	int	i;

	rounding = 0;
	i = idx + 1;
	while (--i > 0)
	{
		obj->fobj.deci_five[i] = obj->fobj.deci_five[i - 1] * 5 % 10 + rounding;
		rounding = obj->fobj.deci_five[i - 1] * 5 / 10;
	}
	obj->fobj.deci_five[0] = rounding;
}

static void		process_deci_res(t_obj *obj, int idx)
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

int	print_double(va_list args, t_obj *obj)
{
	t_fpoint		*fp;
	int				i;

	if (!(fp = init_fobjs()))
		return (0);
	fp->realnum = va_arg(args, double);
	obj->fobj.expnt = fp->bitfield.exponent - BIAS;
	process_deci_bin(obj, fp);
	for (int j = 0; j < 1074; j++)
		ft_putnbr_fd(obj->fobj.deci_bin[j], 1);
	write(1, "\n\n", 2);
	i = 0;
	obj->fobj.deci_five[0] = 5;
	while (i < 52 - obj->fobj.expnt)
	{
		if (obj->fobj.deci_bin[i] == 1)
			process_deci_res(obj, i);
	/*		ft_putnbr_fd(i, 1);
			write(1, "\n", 1);
			for (int j = 0; j < 52 - obj->fobj.expnt; j++)
				ft_putnbr_fd(obj->fobj.deci_five[j], 1);
			write(1, "\n", 1);
			for (int k = 0; k < 52 - obj->fobj.expnt; k++)
				ft_putnbr_fd(obj->fobj.deci_res[k], 1);
			write(1, "\n", 1);
	*/	process_deci_five(obj, ++i);
	}
	for (int i = 0; i < 1074; i++)
		ft_putnbr_fd(obj->fobj.deci_res[i], 1);
	return (1);
}
