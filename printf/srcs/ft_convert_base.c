/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 15:40:37 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/13 14:49:44 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long long	ft_atoll(char *str, int len, int *match)
{
	int			i;
	long long	value;

	i = 0;
	value = 0;
	while (str[i])
	{
		value = value * len + match[(unsigned char)str[i]];
		i++;
	}
	return (value);
}

long long	ft_atoll_base(char *nbr, char *base_from)
{
	int			i;
	int			len;
	int			match[256];
	long long	base_nbr;

	len = ft_strlen(base_from);
	i = 0;
	while (i < 256)
		match[i++] = -1;
	i = 0;
	while (i < len)
	{
		match[(unsigned char)base_from[i]] = i;
		i++;
	}
	base_nbr = ft_atoll(nbr, len, match);
	return (base_nbr);
}

int		res_len(long long nbr, char *base_to)
{
	int	base_len;
	int	res_len;

	base_len = ft_strlen(base_to);
	res_len = 1;
	while (nbr > base_len)
	{
		nbr /= base_len;
		res_len++;
	}
	return (res_len);
}

char	*ft_putnbr_base(long long nbr, int res_len, char *result, char *base_to)
{
	int		base_len;

	base_len = ft_strlen(base_to);
	while (nbr)
	{
		result[--res_len] = base_to[nbr % base_len];
		nbr /= base_len;
	}
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int			len;
	long long	base_nbr;
	char		*result;

	base_nbr = ft_atoll_base(nbr, base_from);
	len = res_len(base_nbr, base_to);
	if (!(result = (char *)calloc(len + 1, sizeof(char))))
		return (NULL);
	return (ft_putnbr_base(base_nbr, len, result, base_to));
}
