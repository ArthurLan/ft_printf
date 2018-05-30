/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 18:43:17 by alanter           #+#    #+#             */
/*   Updated: 2018/05/30 17:19:16 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*penser à la lecture du va_arg dans un autre fichier :
 * fonctionne comme une variable statique ? ou stack ?
*/

void	store_nbr(t_printf *data, va_list lst, int i)
{
	char	*to_add;

	if (TYPE == 's')
		to_add = ft_strdup(va_arg(lst, char *));
	else if (TYPE == 'd' || TYPE == 'i' || TYPE == 'D')
		to_add = ft_itoa(va_arg(lst, int));
	else if (TYPE == 'u' || TYPE == 'U')
		to_add = ft_itoa(va_arg(lst, unsigned int));
	else if (TYPE == 'o' || TYPE == 'O')
		to_add = ft_ulltoa_base(va_arg(lst, unsigned int), 8);
	else if (TYPE == '%')
		to_add = ft_strdup("%");
	else if (TYPE == 'p')
		to_add = ft_strjoin("0x", ft_ulltoa_base(va_arg(lst, long), 16));
	data->result = ft_strjoin(data->result, to_add);
}

/*
void	type_analyse(t_printf *data, int i)
{
	if (TYPE == 'd')
		CAST = "int";
	else if (TYPE == 'u')
		CAST = "unsigned int";
	else
		;
}
*/

void	convert(t_printf *data, va_list lst, int i)//, int j)
{
	/*
	ft_putstr("voilà ma donnée à convertir :");
	ft_putstr(ft_strndup(&(data->str[j]), i - j));
	ft_putstr("\n");
	ft_putstr("voilà mon type :");
	ft_putchar(TYPE);
	ft_putstr("\n");
	*/
	//type_analyse(data, i);
	store_nbr(data, lst, i);
}
