/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:05:12 by alanter           #+#    #+#             */
/*   Updated: 2018/06/01 15:01:49 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/includes/libft.h"

# define TYPE data->type
# define CAST data->cast
# define TO_ADD data->to_add
# define CONV data->conv

typedef struct	s_printf
{
	char	*str;
	char	*result;
	char	*cast;
	char	*to_add;
	char	type;
	int		conv;
	
	//int		init;
	//int		delim;
	//char	conv;
}				t_printf;

int		ft_printf(const char * format, ...);
void	convert(t_printf *data, va_list lst, int i, int j);
#endif
