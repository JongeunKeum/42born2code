/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 15:40:37 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/29 16:56:11 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static unsigned long long	ft_atoull(char *str, int len, int *match)
{
	int					i;
	unsigned long long	value;

	i = 0;
	value = 0;
	while (str[i])
	{
		value = value * len + match[(unsigned char)str[i]];
		i++;
	}
	return (value);
}

static unsigned long long	ft_atoull_base(char *nbr, char *base_from)
{
	int					i;
	int					len;
	int					match[256];
	unsigned long long	base_nbr;

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
	base_nbr = ft_atoull(nbr, len, match);
	return (base_nbr);
}

static int					res_len(unsigned long long nbr, char *base_to)
{
	int	base_len;
	int	res_len;

	base_len = ft_strlen(base_to);
	res_len = 1;
	while (nbr > (unsigned long long)base_len)
	{
		nbr /= base_len;
		res_len++;
	}
	return (res_len);
}

static char					*ft_putnbr_base(unsigned long long nbr,
		int res_len, char *result, char *base_to)
{
	int	base_len;

	base_len = ft_strlen(base_to);
	while (nbr)
	{
		result[--res_len] = base_to[nbr % base_len];
		nbr /= base_len;
	}
	return (result);
}

char						*ft_convert_base(char *nbr,
		char *base_from, char *base_to)
{
	int					len;
	unsigned long long	base_nbr;
	char				*result;

	base_nbr = ft_atoull_base(nbr, base_from);
	len = res_len(base_nbr, base_to);
	free(nbr);
	if (!(result = (char *)ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	return (ft_putnbr_base(base_nbr, len, result, base_to));
}
