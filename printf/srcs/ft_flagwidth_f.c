/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagwidth_f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 17:46:10 by jkeum             #+#    #+#             */
/*   Updated: 2020/12/09 22:16:21 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void print_out_result(t_obj *obj)
{
	for (int k = 309 - obj->fobj.inte_len; k < 309; k++)
		ft_putchar_fd(obj->fobj.inte_res[k], 1);
	if (obj->precision || obj->prefix)
		write(1, ".", 1);
	for (int l = 0; obj->fobj.deci_res[l]; l++)
		ft_putchar_fd(obj->fobj.deci_res[l], 1);
}

static void is_zeroflag_f(t_obj *obj, int range)
{
	int	i;

	i = 0;
	if (obj->zero)
	{
        if (obj->neg)
	    	write(1, "-", 1);
		if (obj->sign && !obj->neg)
			write(1, "+", 1);
        while (i++ < range)
			write(1, "0", 1);
	}
	else
	{
		while (i++ < range)
			write(1, " ", 1);
        if (obj->neg)
		    write(1, "-", 1);
		if (obj->sign && !obj->neg)
			write(1, "+", 1);
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
			write(1, "-", 1);
		if (obj->sign && !obj->neg)
			write(1, "+", 1);
		print_out_result(obj);
		while (i++ < range)
			write(1, " ", 1);
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
	}
	chk_leftflag_f(obj, total_len);
}
