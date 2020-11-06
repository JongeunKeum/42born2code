/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 15:38:45 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/06 16:48:36 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct	s_obj
{
	int		left;
	int		zero;
	int		sign;
	int		space;
	int		prefix;
	int		width;
	int		precision;
	char	type;
	int		len;
	int		idx;
	int		neg;
}				t_obj;

int		print_int(va_list args, t_obj *obj);
int		check_format(const char *str, va_list args, t_obj *obj);

#endif
