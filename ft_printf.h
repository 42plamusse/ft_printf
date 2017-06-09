/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 20:09:50 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/09 17:20:55 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

# define BS 1
# define NO_CONV 1
# define CONV_SUCCEED 1

typedef struct		s_size
{
	int				no;
	int				op;
	int				uc;
}					t_size;

typedef struct		s_fwp
{
	int				fi;
	int				fc;
	int				wi;
	int				pr;
}					t_fwp;

typedef enum		e_flags
{
	fl_ha = 0X01,//	00000001
	fl_ze = 0X02,//	00000010
	fl_mi = 0X04,//	00000100
	fl_pl = 0X08,//	00001000
	fl_sp = 0X10,//	00010000
	//m_fl = 0X1F,//	00011111
}					t_flags;

typedef enum		e_conv
{
	fl_h  = 0X01,//	00000001
	fl_hh = 0X02,//	00000010
	fl_l  = 0X04,//	00000100
	fl_ll = 0X08,//	00001000
	fl_j  = 0X10,//	00010000
	fl_z  = 0X20,//	00100000
	//m_cv = 0X3F,//	00111111
}					t_conv;

int					ft_printf(const char *format, ...);

int					parser(va_list valist, const char *format, char *buf, t_size *sz);

void				init_fwp(t_fwp *fwp);

void				iflags(char *p, t_fwp *fwp);

void				cflag(char *p, t_fwp *fwp, const char *next);

int					converter(va_list valist, char *buf, t_size *sz, const char c, t_fwp *fwp);

int					conv_cs(va_list valist, char *buf, t_size *sz, char c, t_fwp *fwp);

void				stock_s(char *arg, char *buf, t_size *sz, t_fwp *fwp);

void				stock_c(unsigned char arg, char *buf, t_size *sz);

void				stock_S(wchar_t *arg, char *buf, t_size *sz, t_fwp *fwp);

void				stock_C(wchar_t arg, char *buf, t_size *sz, t_fwp *fwp);

void				idt_normls(char *arg, int len, t_size *sz, t_fwp *fwp, char *buf);

void				idt_normlc(char arg, t_size *sz, char *buf);

char				*ft_strchr(const char *s, int c);

size_t				ft_strlen(const char *s);

int					ft_isdigit(int c);

void		init_size(t_size *sz);

#endif
