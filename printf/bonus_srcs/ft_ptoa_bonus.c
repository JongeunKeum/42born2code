/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:00:10 by jkeum             #+#    #+#             */
/*   Updated: 2020/12/09 23:28:33 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_includes/ft_printf_bonus.h"

static int		adr_len(long long n)
{
	int	len;

	len = 1;
	while (n >= 16)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static char		*get_arr_p(char *res, long long n, int len, int sign)
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
			if (n % 16 < 10)
				res[i++] = n % 16 + '0';
			else
				res[i++] = n % 16 + 'a' - 10;
			n /= 16;
		}
		if (sign == 1)
			res[i] = '-';
		res = ft_strrev(res);
	}
	return (res);
}

char			*ft_ptoa(long long n)
{
	int		len;
	int		sign;
	char	*res;

	if (n == LLONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n *= -1;
	}
	len = adr_len(n);
	if (!(res = (char *)malloc(len + sign + 1)))
		return (NULL);
	return (get_arr_p(res, n, len, sign));
}
