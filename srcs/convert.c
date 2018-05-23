/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 18:43:17 by alanter           #+#    #+#             */
/*   Updated: 2018/05/23 17:42:21 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*penser à la lecture du va_arg dans un autre fichier :
 * fonctionne comme une variable statique ? ou stack ?
*/

void	store_nbr(t_printf *data, va_list lst)//, int j)
{
	char	*to_add;

	to_add = ft_itoa(va_arg(lst, int));
	data->result = ft_strjoin(data->result, to_add);
}

void	type_analyse(t_printf *data, int i)
{
	if (TYPE == 'd')
		CAST = "int";
	else if (TYPE == 'u')
		CAST = "unsigned int";
	else
		;
}

void	convert(t_printf *data, va_list lst, int i, int j)
{
	ft_putstr("voilà ma donnée à convertir :");
	ft_putstr(ft_strndup(&(data->str[j]), i - j));
	ft_putstr("\n");
	ft_putstr("voilà mon type :");
	ft_putchar(TYPE);
	ft_putstr("\n");
	type_analyse(data, i);
	if (!(TYPE == '%'))
		store_nbr(data, lst);
	i++;
	j++;
	lst++;
}
