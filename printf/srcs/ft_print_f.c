/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:40:30 by jkeum             #+#    #+#             */
/*   Updated: 2020/12/06 03:24:04 by jkeum            ###   ########.fr       */
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

int	print_double(va_list args, t_obj *obj)
{
	t_fpoint		*fp;
	int				i;
	int				j;

	if (!(fp = init_fobjs()))
		return (0);
	fp->realnum = va_arg(args, double);
	obj->fobj.expnt = fp->bitfield.exponent - BIAS;

	// 소수부분
	process_deci_bin(obj, fp);
/*	for (int j = 0; j < 1074; j++)
		ft_putnbr_fd(obj->fobj.deci_bin[j], 1);
	write(1, "\n\n", 2);
*/	i = 0;
	obj->fobj.deci_five[0] = 5;
	while (i < 51 - obj->fobj.expnt)	//52일 때 __DBL_MIN__에서 앞에 5가 출력됨.
	{
		if (obj->fobj.deci_bin[i] == 1)
			process_deci_res(obj, i);
	//		ft_putnbr_fd(i, 1);
	//		write(1, "\n", 1);
	/*		for (int k = 0; k < 52 - obj->fobj.expnt; k++)
				ft_putnbr_fd(obj->fobj.deci_res[k], 1);
			write(1, "\n", 1);
	*/	process_deci_five(obj, ++i);
/*		for (int j = 0; j < 52 - obj->fobj.expnt; j++)
			ft_putnbr_fd(obj->fobj.deci_five[j], 1);
		write(1, "\n", 1);
*/	}
	for (int i = 0; i < 1074; i++)
		ft_putnbr_fd(obj->fobj.deci_res[i], 1);

	// 정수부분
	obj->fobj.rounding = 0;
	process_inte_bin(obj, fp);
	obj->fobj.inte_two[0] = 1;
	i = -1;
	j = 1024;
	while (++i <= obj->fobj.expnt)
	{
		if (obj->fobj.inte_bin[--j] == 1)
		{
			process_inte_res(obj);
/*			for (int k = 0; k < 309; k++)
				ft_putnbr_fd(obj->fobj.inte_res[k], 1);
			write(1, "\n", 1);
*/		}
		process_inte_two(obj);
/*		for (int j = 0; j < 52; j++)
			ft_putnbr_fd(obj->fobj.inte_two[j], 1);
		write(1, "\n", 1);
		ft_putnbr_fd(obj->fobj.two, 1);
		write(1, "\n", 1);
*/	}
	ft_strrev_f(obj);
//	for (int k = 0; k < 309; k++)
//		ft_putnbr_fd(obj->fobj.inte_res[k], 1);
	return (1);
}
