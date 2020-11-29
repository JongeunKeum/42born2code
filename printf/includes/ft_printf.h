/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 15:38:45 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/29 17:04:27 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct		s_obj
{
	int		left;
	int		zero;
	int		sign;
	int		space;
	int		prefix;
	int		oct_prefix;
	int		width;
	int		precision;
	char	type;
	int		len;
	int		idx;
	int		neg;
	int		dot;
	int		length;
	int		return_value;
	char	*res;
}					t_obj;

int					ft_printf(const char *str, ...);
int					print_int(va_list args, t_obj *obj);
int					print_char(va_list args, t_obj *obj);
int					print_str(va_list args, t_obj *obj);
int					print_unsigned_int(va_list args, t_obj *obj);
int					print_hex(va_list args, t_obj *obj);
int					print_oct(va_list args, t_obj *obj);
int					print_address(va_list args, t_obj *obj);
int					print_percent(t_obj *obj);
int					print_num_ch(va_list args, t_obj *obj);
int					check_format(const char *str, va_list args, t_obj *obj);
void				check_length(const char *str, t_obj *obj);
int					fill_precision_nbr(t_obj *obj);
int					fill_width(t_obj *obj);
char				*ft_lltoa(long long n);
char				*ft_strrev(char *str);
char				*ft_ulltoa(unsigned long long n);
char				*ft_ptoa(long long n);
char				*ft_convert_base(char *nbr, char *base_from, char *base_to);
char				*ft_strjoin_free(char *s1, char *s2, int to_free);

#endif
