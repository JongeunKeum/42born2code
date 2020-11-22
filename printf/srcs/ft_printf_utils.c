/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:46:44 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/21 17:32:39 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	check_length(const char *str, t_obj *obj)
{
	if (str[obj->idx] == 'l')
	{
		if (str[obj->idx + 1] == 'l')
		{
			obj->length = 4;
			obj->idx++;
		}
		else
			obj->length = 3;
		obj->idx++;
	}
	else if (str[obj->idx] == 'h')
	{
		if (str[obj->idx + 1] == 'h')
		{
			obj->length = 2;
			obj->idx++;
		}
		else
			obj->length = 1;
		obj->idx++;
	}
}
