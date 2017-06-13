/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 20:09:50 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/13 17:14:54 by plamusse         ###   ########.fr       */
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

/*
** structs
*/
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

typedef struct		s_dif
{
	int				al;
	int				pl;
	int				wl;
}					t_dif;
/*
** enums
*/
typedef enum		e_flags
{
	fl_ha = 0X01,//	00000001
	fl_ze = 0X02,//	00000010
	fl_mi = 0X04,//	00000100
	fl_pl = 0X08,//	00001000
	fl_sp = 0X10,//	00010000
	fl_ne = 0X20,
	fl_pr = 0X40,
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
/*
** prototypes
*/
int					ft_printf(const char *format, ...);
void				init_size(t_size *sz);
/*
** parsing
*/
void				init_fwp(t_fwp *fwp);
int					parser(va_list valist, const char *format, char *buf, t_size *sz);
void				iflags(char *p, t_fwp *fwp);
void				cflag(char *p, t_fwp *fwp, const char *next);
/*
** conversion
*/
int					converter(va_list valist, char *buf, t_size *sz, const char c, t_fwp *fwp);
int					conv_cs(va_list valist, char *buf, t_size *sz, char c, t_fwp *fwp);
int					conv_si(va_list valist, char *buf, t_size *sz, char c, t_fwp *fwp);
/*
** stock
*/
void				stock_s(char *arg, char *buf, t_size *sz, t_fwp *fwp);
void				stock_c(unsigned char arg, char *buf, t_size *sz, t_fwp *fwp);
void				stock_S(wchar_t *arg, char *buf, t_size *sz, t_fwp *fwp);
void				stock_C(wchar_t arg, char *buf, t_size *sz, t_fwp *fwp);
void				stock_si(ssize_t arg, char *buf, t_size *sz, t_fwp *fwp);
/*
** indentation
*/
void				fill_ze(char *buf, t_size *sz, int nsp);
void				fill_sp(char *buf, t_size *sz, int nsp);
void				putsign(t_size *sz, t_fwp *fwp, char *buf);
char				*itoa_deci(size_t arg, int len);
void				idt_normls(char *arg, int len, t_size *sz, t_fwp *fwp, char *buf);
void				idt_normlc(char arg, t_size *sz, char *buf);
void				idt_normlsi(ssize_t arg, t_dif *df, t_size *sz, t_fwp *fwp, char *buf);
void				idt_rights(char *arg, int len, t_size *sz, t_fwp *fwp, char *buf);
void				idt_rightc(char arg, t_size *sz, t_fwp *fwp, char *buf);
void				idt_rightsi(ssize_t arg, t_dif *df, t_size *sz, t_fwp *fwp, char *buf);
void				idt_zeros(char *arg, int len, t_size *sz, t_fwp *fwp, char *buf);
void				idt_zeroc(char arg, t_size *sz, t_fwp *fwp, char *buf);
void				idt_zerosi(ssize_t arg, t_dif *df, t_size *sz, t_fwp *fwp, char *buf);
void				idt_lefts(char *arg, int len, t_size *sz, t_fwp *fwp, char *buf);
void				idt_leftc(char arg, t_size *sz, t_fwp *fwp, char *buf);
void				idt_leftsi(ssize_t arg, t_dif *df, t_size *sz, t_fwp *fwp, char *buf);
#endif
