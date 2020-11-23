/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:23:05 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/23 13:23:06 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void    is_left(t_obj *obj, int len, int flag)
{
    char    *wid;

    wid = (char *)calloc(len + 1, 1);
    if (obj->space)
        obj->res = ft_strjoin(" ", obj->res);
    else if (obj->sign)
        obj->res = ft_strjoin("+", obj->res);
    else if (obj->neg)
        obj->res = ft_strjoin("-", obj->res);
    else if (obj->prefix == 2)
        obj->res = ft_strjoin("0x", obj->res);
    else if (obj->prefix == 1)
        obj->res = ft_strjoin("0", obj->res);
    wid = ft_memset(wid + flag + obj->prefix, ' ', len - flag - obj->prefix);
    obj->res = ft_strjoin(obj->res, wid);
    free(wid - flag - obj->prefix);
}

void    is_zeroflag(t_obj *obj, int len, int flag)
{
    char    *wid;

    wid = (char *)calloc(obj->width + 1, 1);
    if (obj->space)
        wid[0] = ' ';
    else if (obj->sign)
        wid[0] = '+';
    else if (obj->neg)
        wid[0] = '-';
    ft_memset(wid + flag, '0', len - flag);
    if (obj->prefix == 2)
        wid[1] = 'x';
    obj->res = ft_strjoin(wid, obj->res);
    free(wid);
}

void    no_left_zeroflag(t_obj *obj, int len, int flag)
{
    char    *wid;

    wid = (char *)calloc(obj->width + 1, 1);
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
    wid[len] = '\0';
    obj->res = ft_strjoin(wid, obj->res);
    free(wid);
}

void	fill_width(t_obj *obj)
{
	int		len;
	int		prev_len;
	int		flag;

	prev_len = ft_strlen(obj->res);
	len = obj->width - prev_len;
	flag = obj->neg | obj->space | obj->sign;
	if (obj->prefix == 1 && obj->dot)
		obj->prefix = 0;
	if (obj->left)
        is_left(obj, len, flag);
	else
	{
		if (!obj->dot && obj->zero)
            is_zeroflag(obj, len, flag);
		else
            no_left_zeroflag(obj, len, flag);
	}
}