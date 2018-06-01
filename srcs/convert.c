/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 18:43:17 by alanter           #+#    #+#             */
/*   Updated: 2018/06/01 15:17:31 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*penser à la lecture du va_arg dans un autre fichier :
 * fonctionne comme une variable statique ? ou stack ?
*/

/*
** ---- Flag conversiont : CONV = ... ----
**
** ---- hh	1
** ---- h	2
** ---- l	3
** ---- ll	4
** ---- j	5
** ---- z	6
*/

// créer un itoa pour les short et les char ?

void	store_di(t_printf *data, va_list lst)
{
	if (CONV == 0 || CONV == 1 || CONV == 2)
		TO_ADD = ft_itoa(va_arg(lst, int));
	/*
	else if (CONV == 1)
		TO_ADD = ft_itoa(va_arg(lst, char));
	else if (CONV == 2)
		TO_ADD = ft_itoa(va_arg(lst, short int));
		*/
	else if (CONV == 3)
		TO_ADD = ft_ulltoa_base(va_arg(lst, long int), 10);
	else if (CONV == 4)
		TO_ADD = ft_ulltoa_base(va_arg(lst, long long int), 10);
	else if (CONV == 5)
		TO_ADD = ft_ulltoa_base(va_arg(lst, intmax_t), 10);
	else if (CONV == 6)
		TO_ADD = ft_ulltoa_base(va_arg(lst, size_t), 10);
}

void	store_uoxp(t_printf *data, va_list lst, int base)
{
	if (CONV == 0 || CONV == 1 || CONV == 2)
		TO_ADD = ft_ulltoa_base(va_arg(lst, unsigned int), base);
	/*
	else if (CONV == 1)
		TO_ADD = ft_ulltoa_base(va_arg(lst, unsigned char), base);
	else if (CONV == 2)
		TO_ADD = ft_ulltoa_base(va_arg(lst, unsigned short int), base);
		*/
	else if (CONV == 3)
		TO_ADD = ft_ulltoa_base(va_arg(lst, unsigned long int), base);
	else if (CONV == 4)
		TO_ADD = ft_ulltoa_base(va_arg(lst, unsigned long long int), base);
	else if (CONV == 5)
		TO_ADD = ft_ulltoa_base(va_arg(lst, uintmax_t), base);
	else if (CONV == 6)
		TO_ADD = ft_ulltoa_base(va_arg(lst, size_t), base);
}

void	type_analyse(t_printf *data, int i, int j)
{
	char *flags;

	CONV = 0;
	flags = NULL;
	while (j < i && CONV == 0)
	{
		flags = ft_strndup(&(data->str[j]), i-j);
		if (data->str[j] == 'h')
			CONV = (ft_strrchr(flags, 'h') != flags) ? 1 : 2;
		if (data->str[j] == 'l')
			CONV = (ft_strrchr(flags, 'l') != flags) ? 4 : 3;
		if (data->str[j] == 'j')
			CONV = 5;
		if (data->str[j] == 'z')
			CONV = 6;
		j++;
	}
}

void	convert(t_printf *data, va_list lst, int i, int j)
{
	int base;
	base = 10;
	type_analyse(data, i, j);
	TYPE = data->str[i - 1];
	base = (ft_strchr("oO", TYPE)) ? 8 : (base = (ft_strchr("xXp", TYPE)) ? 16 : 10);
	if (TYPE == 's' || TYPE == 'S' || TYPE == 'c' || TYPE == 'C')
	{
		if (TYPE == 'c')
			TO_ADD = ft_strdup(va_arg(lst, char));
		else
			TO_ADD = ft_strdup(va_arg(lst, char *));
	}
	else if (TYPE == 'd' || TYPE == 'i' || TYPE == 'D')
		store_di(data, lst);
	else if (ft_strchr("oOuUxXp", TYPE) != NULL)
		store_uoxp(data, lst, base);
	else if (TYPE == '%')
		TO_ADD = ft_strdup("%");
	data->result = ft_strjoin(data->result, TO_ADD);
}



	/*
	ft_putstr("voilà ma donnée à convertir :");
	ft_putstr(ft_strndup(&(data->str[j]), i - j));
	ft_putstr("\n");
	ft_putstr("voilà mon type :");
	ft_putchar(TYPE);
	ft_putstr("\n");
	*/
/*
 *
	ft_putstr("\nMon option d'analyse est égale à : ");
	ft_putnbr(CONV);
	ft_putstr("\n");
	ft_putstr("\nVoilà mon TYPE :");
	ft_putchar(TYPE);
	ft_putstr("\nMon option base est égale à : ");
	ft_putnbr(base);
	ft_putstr("\n");
	*/
	/*
	ft_putstr("\nMon option d'analyse est égale à : ");
	ft_putnbr(CONV);
	ft_putstr("\n");
	*/
/*
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
*/
