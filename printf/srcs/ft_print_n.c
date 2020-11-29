/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:50:46 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/29 15:39:50 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_num_ch(va_list args, t_obj *obj)
{
	long long	n;

	n = obj->return_value;
	if (obj->length == 3)
		*(long *)va_arg(args, void *) = (long)n;
	else if (obj->length == 4)
		*(long long *)va_arg(args, void *) = (long long)n;
	else if (obj->length == 2)
		*(char *)va_arg(args, void *) = (char)n;
	else if (obj->length == 1)
		*(short *)va_arg(args, void *) = (short)n;
	else
		*(int *)va_arg(args, void *) = (int)n;
	return (1);
}
