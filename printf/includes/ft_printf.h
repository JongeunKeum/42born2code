/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 15:38:45 by jkeum             #+#    #+#             */
/*   Updated: 2020/11/23 13:10:45 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct	s_obj
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
}				t_obj;

int					print_int(va_list args, t_obj *obj);
int					print_char(va_list args, t_obj *obj);
int					print_str(va_list args, t_obj *obj);
int					print_unsigned_int(va_list args, t_obj *obj);
int					print_hex(va_list args, t_obj *obj);
int					print_oct(va_list args, t_obj *obj);
int					print_address(va_list args, t_obj *obj);
int					print_percent(t_obj *obj);
int					print_num_ch(va_list args, t_obj *obj);
long long			get_num_d(va_list args, t_obj *obj);
unsigned long long	get_num_u(va_list args, t_obj *obj);
unsigned long long	get_num_o(va_list args, t_obj *obj);
unsigned long long	get_num_x(va_list args, t_obj *obj);
void				check_width(const char *str, t_obj *obj, va_list args);
void				check_precision(const char *str, t_obj *obj, va_list args);
void				check_flag(const char *str, t_obj *obj);
int					check_type(va_list args, t_obj *obj);
int					check_format(const char *str, va_list args, t_obj *obj);
void				check_length(const char *str, t_obj *obj);
void				fill_precision_nbr(t_obj *obj);
void				fill_width(t_obj *obj);
void				fill_width_null(t_obj *obj, char c);
void				is_left(t_obj *obj, int len, int flag);
void				is_zeroflag(t_obj *obj, int len, int flag);
void				no_left_zeroflag(t_obj *obj, int len, int flag);
void				is_not_null_c(t_obj *obj, char c);
void				is_type_X(t_obj *obj);
void				process_width_x(t_obj *obj);
char				*ft_lltoa(long long n);
char				*ft_ptoa(long long n);
char				*ft_convert_base(char *nbr, char *base_from, char *base_to);

#endif
