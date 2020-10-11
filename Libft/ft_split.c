/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 08:23:09 by jkeum             #+#    #+#             */
/*   Updated: 2020/10/10 14:31:58 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	cnt_words(char const *s, char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			cnt++;
		}
		else
			i++;
	}
	return (cnt);
}

static char		*get_arr(char const *s, char c, char *res, size_t idx)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (s[idx + len] != c && s[idx + len] != '\0')
		len++;
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s[idx + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char			**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	res_idx;
	char	**res;

	res = (char **)malloc(sizeof(char *) * (cnt_words(s, c) + 1));
	if (!res)
		return (NULL);
	i = 0;
	res_idx = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		res[res_idx] = get_arr(s, c, res[res_idx], i);
		res_idx++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	res[res_idx] = ft_strdup("");
	res[res_idx] = NULL;
	return (res);
}
