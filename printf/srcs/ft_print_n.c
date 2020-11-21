/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:50:46 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/18 15:50:18 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_num_ch(va_list args, t_obj *obj)
{
	int	*n;

	n = (int *)va_arg(args, void *);
	*n = obj->return_value;
	return (1);
}
