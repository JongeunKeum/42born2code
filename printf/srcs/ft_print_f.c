/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:40:30 by jkeum             #+#    #+#             */
/*   Updated: 2020/12/09 17:48:45 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

void	fill_deci_inte(t_obj *obj, t_fpoint *fp)
{
	int	i;
	int	j;

	obj->fobj.expnt = fp->bitfield.exponent - BIAS;
	process_deci_bin(obj, fp);
	i = 0;
	obj->fobj.deci_five[0] = 5;
	while (i < 51 - obj->fobj.expnt)
	{
		if (obj->fobj.deci_bin[i] == 1)
			process_deci_res(obj, i);
		process_deci_five(obj, ++i);
	}
	obj->fobj.rounding = 0;
	process_inte_bin(obj, fp);
	obj->fobj.inte_two[0] = 1;
	i = -1;
	j = 1024;
	while (++i <= obj->fobj.expnt)
	{
		if (obj->fobj.inte_bin[--j] == 1)
			process_inte_res(obj);
		process_inte_two(obj);
	}
	ft_strrev_f(obj);
}

int		print_double(va_list args, t_obj *obj)
{
	t_fpoint		*fp;

	if (!(fp = init_fobjs()))
		return (0);
	fp->realnum = va_arg(args, double);
	obj->neg = fp->bitfield.sign;
	fill_deci_inte(obj, fp);
	cut_precision_f(obj);
	flag_n_width_f(obj);
	return (1);
}
