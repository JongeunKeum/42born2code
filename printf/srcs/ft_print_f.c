/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:40:30 by jkeum             #+#    #+#             */
/*   Updated: 2020/12/09 23:51:13 by jkeum            ###   ########.fr       */
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

void			print_out_result(t_obj *obj)
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

static void		fill_deci(t_obj *obj, t_fpoint *fp)
{
	int	i;

	obj->fobj.expnt = fp->bitfield.exponent - BIAS;
	process_deci_bin(obj, fp);
	i = 0;
	obj->fobj.deci_five[0] = 5;
	while (i < 52 - obj->fobj.expnt)
	{
		if (obj->fobj.deci_bin[i] == 1)
			process_deci_res(obj, i);
		process_deci_five(obj, ++i);
	}
	if (fp->bitfield.mantissa == 0)
		ft_bzero(obj->fobj.deci_res, 1074);
	if (fp->realnum == __DBL_MIN__)
		obj->fobj.deci_res[0] = 0;
}

static void		fill_inte(t_obj *obj, t_fpoint *fp)
{
	int	i;
	int	j;

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

int				print_double(va_list args, t_obj *obj)
{
	t_fpoint		*fp;

	if (!(fp = init_fobjs()))
		return (0);
	fp->realnum = va_arg(args, double);
	obj->neg = fp->bitfield.sign;
	fill_deci(obj, fp);
	fill_inte(obj, fp);
	cut_precision_f(obj);
	flag_n_width_f(obj);
	return (1);
}
