/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 20:12:57 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/29 17:07:12 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		n_len_u(unsigned long long n)
{
	int	len;

	len = 1;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char		*get_arr_u(char *res, unsigned long long n,
		int len, int sign)
{
	int	i;

	i = 0;
	res[len + sign] = '\0';
	if (n == 0)
		res[i] = '0';
	else
	{
		while (n > 0)
		{
			res[i++] = n % 10 + '0';
			n /= 10;
		}
		if (sign == 1)
			res[i] = '-';
		res = ft_strrev(res);
	}
	return (res);
}

char			*ft_ulltoa(unsigned long long n)
{
	int		len;
	int		sign;
	char	*res;

	if (n == 0)
		return (ft_strdup("0"));
	sign = 0;
	len = n_len_u(n);
	if (!(res = (char *)malloc(len + sign + 1)))
		return (NULL);
	return (get_arr_u(res, n, len, sign));
}
