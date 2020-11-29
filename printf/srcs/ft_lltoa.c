/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:00:10 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/29 16:56:46 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		n_len(long long n)
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

char			*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	tmp;

	len = ft_strlen(str);
	i = 0;
	while (i < --len)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i++;
	}
	return (str);
}

static char		*get_arr(char *res, long long n, int len, int sign)
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

char			*ft_lltoa(long long n)
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
	len = n_len(n);
	if (!(res = (char *)malloc(len + sign + 1)))
		return (NULL);
	return (get_arr(res, n, len, sign));
}
