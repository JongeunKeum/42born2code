/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:23:05 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/29 16:55:10 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	is_left(t_obj *obj, int len, int flag)
{
	char	*wid;

	if (!(wid = (char *)ft_calloc(len + 1, 1)))
		return (0);
	if (obj->space)
		obj->res = ft_strjoin_free(" ", obj->res, 2);
	else if (obj->sign)
		obj->res = ft_strjoin_free("+", obj->res, 2);
	else if (obj->neg)
		obj->res = ft_strjoin_free("-", obj->res, 2);
	else if (obj->prefix == 2)
		obj->res = ft_strjoin_free("0x", obj->res, 2);
	else if (obj->prefix == 1)
		obj->res = ft_strjoin_free("0", obj->res, 2);
	wid = ft_memset(wid + flag + obj->prefix, ' ', len - flag - obj->prefix);
	if (!(obj->res = ft_strjoin_free(obj->res, wid, 1)))
	{
		free(wid - flag - obj->prefix);
		return (0);
	}
	free(wid - flag - obj->prefix);
	return (1);
}

static int	is_zeroflag(t_obj *obj, int len, int flag)
{
	char	*wid;

	if (!(wid = (char *)ft_calloc(obj->width + 1, 1)))
		return (0);
	if (obj->space)
		wid[0] = ' ';
	else if (obj->sign)
		wid[0] = '+';
	else if (obj->neg)
		wid[0] = '-';
	ft_memset(wid + flag, '0', len - flag);
	if (obj->prefix == 2)
		wid[1] = 'x';
	if (!(obj->res = ft_strjoin_free(wid, obj->res, 2)))
	{
		free(wid);
		return (0);
	}
	free(wid);
	return (1);
}

static int	no_left_zeroflag(t_obj *obj, int len, int flag)
{
	char	*wid;

	if (!(wid = (char *)ft_calloc(obj->width + 1, 1)))
		return (0);
	wid = ft_memset(wid, ' ', len - flag - obj->prefix);
	if (obj->space)
		wid[len - flag] = ' ';
	else if (obj->sign)
		wid[len - flag] = '+';
	else if (obj->neg)
		wid[len - flag] = '-';
	else if (obj->prefix == 2)
	{
		wid[len - flag - obj->prefix] = '0';
		wid[len - flag - obj->prefix + 1] = 'x';
	}
	else if (obj->prefix == 1)
		wid[len - flag - obj->prefix] = '0';
	if (!(obj->res = ft_strjoin_free(wid, obj->res, 2)))
	{
		free(wid);
		return (0);
	}
	free(wid);
	return (1);
}

int			fill_width(t_obj *obj)
{
	int	len;
	int	prev_len;
	int	flag;
	int	valid;

	prev_len = ft_strlen(obj->res);
	len = obj->width - prev_len;
	flag = obj->neg | obj->space | obj->sign;
	valid = 1;
	if (obj->prefix == 1 && obj->dot)
		obj->prefix = 0;
	if (obj->left)
		valid = is_left(obj, len, flag);
	else
	{
		if (!obj->dot && obj->zero)
			valid = is_zeroflag(obj, len, flag);
		else
			valid = no_left_zeroflag(obj, len, flag);
	}
	if (!valid)
		return (0);
	return (1);
}
