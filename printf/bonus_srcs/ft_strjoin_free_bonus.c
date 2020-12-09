/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 11:34:47 by jkeum             #+#    #+#             */
/*   Updated: 2020/12/09 23:28:36 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_includes/ft_printf_bonus.h"

char	*ft_strjoin_free(char *s1, char *s2, int to_free)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	if (to_free == 1)
		free(s1);
	if (to_free == 2)
		free(s2);
	return (res);
}
