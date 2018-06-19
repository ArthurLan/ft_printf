/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:05:12 by alanter           #+#    #+#             */
/*   Updated: 2018/06/19 20:23:53 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/includes/libft.h"
# include <wchar.h>

/*
 * **	-- Every macro is used to access data structure MAJ = data->maj --
 * **
 * ** 	TO_ADD	= STR TO JOIN TO RESULT
 * ** 	SCAN 	= data to analyse, ex : %-.9d
 * **	TYPE	= type from SCAN,  ex : d
 * **	FLAG	= flag "#+ -0" precision and padding, ex : -.9
 * **	CONV	= type conversion "hh, h, l, ll..."
 */

# define TO_ADD data->to_add
# define ADD_FLAG data->add_flag
# define SCAN data->scan
# define TYPE data->type
# define FLAG data->flag
# define SPEC data->spec

typedef struct	s_printf
{
	char	*str;
	char	*result;
	char	*to_add;
	char	*add_flag;
	char	*scan;
	char	type;
	int		*flag;
	int		spec;
	
	//int		init;
	//int		delim;
	//char	conv;
}				t_printf;

int		ft_printf(const char * format, ...);
void	convert(t_printf *data, va_list lst, int i, int j);
void	flags(t_printf *data, int i, int j);
#endif
