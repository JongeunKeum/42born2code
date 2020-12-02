/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:40:30 by jkeum             #+#    #+#             */
/*   Updated: 2020/12/02 22:00:31 by jkeum            ###   ########.fr       */
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

int	print_double(va_list args, t_obj *obj)
{
	t_fpoint		*fp;
	int				i;
	int				j;

	fp = init_fobjs();
	fp->realnum = va_arg(args, double);
	obj->fobj.expnt = fp->bitfield.exponent - BIAS;
	if (obj->fobj.expnt >= 0)
	{
		fp->bitfield.mantissa <<= obj->fobj.expnt;
		i = -1;
		while (i++ < 52)
		{
			if ((fp->bitfield.mantissa >> (51 - i)) & 1)
				obj->fobj.deci_bin[i] = '1';
		}
	}
	else
	{
		i = obj->fobj.expnt * (-1) - 1;
		obj->fobj.deci_bin[i] = '1';
		j = obj->fobj.expnt * -1;
		while (++i < 52 + j)
		{
			if ((fp->bitfield.mantissa >> (51 - i + j)) & 1)
				obj->fobj.deci_bin[i] = '1';
		}
	}
	ft_putstr_fd(obj->fobj.deci_bin, 1);

	return (1);
}
