/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:05:12 by alanter           #+#    #+#             */
/*   Updated: 2018/05/22 15:23:38 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/includes/libft.h"


typedef struct	s_printf
{
	char	*str;
	char	*result;
	//int		init;
	//int		delim;
	//char	conv;
}				t_printf;

int		ft_printf(const char * format, ...);
void	convert(t_printf *data, va_list lst, int i, int j);
#endif
