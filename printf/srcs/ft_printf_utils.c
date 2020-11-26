/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:46:44 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/26 17:08:16 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	check_length(const char *str, t_obj *obj)
{
	int	l_cnt;
	int	h_cnt;

	l_cnt = 0;
	h_cnt = 0;
	while (ft_strchr("lh", str[obj->idx]))
	{
		if (str[obj->idx] == 'l')
			l_cnt++;
		else
			h_cnt++;
		obj->idx++;
	}
	if (l_cnt > 1)
		obj->length = 4;
	else if (l_cnt == 1)
		obj->length = 3;
	else if (h_cnt > 1)
		obj->length = 2;
	else if (h_cnt == 1)
		obj->length = 1;
}
