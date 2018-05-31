/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 18:43:17 by alanter           #+#    #+#             */
/*   Updated: 2018/05/31 17:58:58 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*penser à la lecture du va_arg dans un autre fichier :
 * fonctionne comme une variable statique ? ou stack ?
*/

// ajouter tous les casts possibles, trouver les équivalences avec les options
void	store_nbr(t_printf *data, va_list lst)
{
	if (TYPE == 's')
		TO_ADD = ft_strdup(va_arg(lst, char *));
	else if (TYPE == 'd' || TYPE == 'i' || TYPE == 'D')
		TO_ADD = ft_itoa(va_arg(lst, int));
	else if (TYPE == 'u' || TYPE == 'U')
		TO_ADD = ft_itoa(va_arg(lst, unsigned int));
	else if (TYPE == 'o' || TYPE == 'O')
		TO_ADD = ft_ulltoa_base(va_arg(lst, unsigned int), 8);
	else if (TYPE == '%')
		TO_ADD = ft_strdup("%");
	else if (TYPE == 'p')
		TO_ADD = ft_strjoin("0x", ft_ulltoa_base(va_arg(lst, long), 16));
	else
		TO_ADD = ft_strdup("\n------still to deal with------\n");
}

/*
**hh	1
**h		2
**l		3
**ll	4
**j		5
**z		6
*/

void	type_analyse(t_printf *data, int i, int j)
{
	CONV = 0;
	while (j < i && CONV == 0)
	{
		if (data->str[j] == 'h')
			//ft_strchr(ft_strndup(&(data->str[j]), i-j), 'h') != NULL ? CONV = 1 : CONV = 2;
			ft_strchr("test", 'h') == NULL ? CONV = 1 : CONV = 2;
		if (data->str[j] == 'l')
			;//ft_strchr(ft_strndup(&(data->str[j]), i-j), 'h') != NULL ? CONV = 3 : CONV = 4;
		if (data->str[j] == 'j')
			CONV = 5;
		if (data->str[j] == 'z')
			CONV = 6;
		j++;
	}
}



void	convert(t_printf *data, va_list lst, int i, int j)
{

	/*
	ft_putstr("voilà ma donnée à convertir :");
	ft_putstr(ft_strndup(&(data->str[j]), i - j));
	ft_putstr("\n");
	ft_putstr("voilà mon type :");
	ft_putchar(TYPE);
	ft_putstr("\n");
	*/
	type_analyse(data, i, j);
	TYPE = data->str[i - 1];
/*	
	if (TYPE == 's')
		TO_ADD = ft_strdup(va_arg(lst, char *));
	else if (TYPE == 'd' || TYPE == 'i' || TYPE == 'D')
		store_di;
	else if (TYPE == 'u' || TYPE == 'U')
		TO_ADD = ft_itoa(va_arg(lst, unsigned int));
	else if (TYPE == 'o' || TYPE == 'O')
		TO_ADD = ft_ulltoa_base(va_arg(lst, unsigned int), 8);
*/
	store_nbr(data, lst);
	data->result = ft_strjoin(data->result, TO_ADD);
}
