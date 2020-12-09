/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:46:44 by jkeum             #+#    #+#             */
/*   Updated: 2020/12/09 23:28:23 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_includes/ft_printf_bonus.h"

int		fill_precision_nbr(t_obj *obj)
{
	int		i;
	int		len;
	char	*prec;

	len = obj->precision - obj->len + obj->neg;
	if (!(prec = (char *)ft_calloc(len + 1, 1)))
		return (0);
	i = 0;
	while (i < len)
		prec[i++] = '0';
	if (!(obj->res = ft_strjoin_free(obj->res, prec, 1)))
	{
		free(prec);
		return (0);
	}
	free(prec);
	return (1);
}

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
