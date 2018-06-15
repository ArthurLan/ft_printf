/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 18:43:17 by alanter           #+#    #+#             */
/*   Updated: 2018/06/15 18:39:09 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*penser à la lecture du va_arg dans un autre fichier :
 * fonctionne comme une variable statique ? ou stack ?
*/

/*
 * ** ---- SPEC = int to deal with specifiers ----
 * **
 * **---- hh	1
 * **---- h		2
 * **---- l		3
 * **---- ll	4
 * **---- j		5
 * **---- z		6
 * */

void	store_di(t_printf *data, va_list lst)
{
	if (SPEC == 0)
		TO_ADD = ft_itoa(va_arg(lst, int));
	else if (SPEC == 1)
		TO_ADD = ft_itoa((char)(va_arg(lst, int)));
	else if (SPEC == 2)
		TO_ADD = ft_itoa((short int)(va_arg(lst, int)));
	else if (SPEC == 3)
		TO_ADD = ft_lltoa_base(va_arg(lst, long int), 10);
	else if (SPEC == 4)
		TO_ADD = ft_lltoa_base(va_arg(lst, long long int), 10);
	else if (SPEC == 5)
		TO_ADD = ft_lltoa_base(va_arg(lst, intmax_t), 10);
	else if (SPEC == 6)
		TO_ADD = ft_lltoa_base(va_arg(lst, size_t), 10);
}

//verifier SPEC 1 et 2, les parentheses
void	store_uoxp(t_printf *data, va_list lst, int base)
{
	if (SPEC == 0 && TYPE != 'p')
		TO_ADD = ft_ulltoa_base(va_arg(lst, unsigned int), base);
	else if (SPEC == 1 && TYPE != 'U')
		TO_ADD = ft_ulltoa_base((unsigned char)(va_arg(lst, int)), base);
	else if (SPEC == 2 && TYPE != 'U')
		TO_ADD = ft_ulltoa_base((unsigned short int)(va_arg(lst, int)), base);
	else if (SPEC == 3 || TYPE == 'p')
		TO_ADD = ft_ulltoa_base(va_arg(lst, unsigned long int), base);
	else if (SPEC == 4 || TYPE == 'U')
		TO_ADD = ft_ulltoa_base(va_arg(lst, unsigned long long int), base);
	else if (SPEC == 5)
		TO_ADD = ft_ulltoa_base(va_arg(lst, uintmax_t), base);
	else if (SPEC == 6)
		TO_ADD = ft_ulltoa_base(va_arg(lst, size_t), base);
}

void	store_cs(t_printf *data, va_list lst)
{
	if ((SPEC == 3 && TYPE == 'c') || TYPE == 'C')
			TO_ADD = ft_ctostr((wint_t)(va_arg(lst, wint_t)));
	else if ((SPEC == 3 && TYPE == 's') || TYPE == 'S')
			TO_ADD = ft_wtostr(va_arg(lst, wchar_t *));
	else if (TYPE == 'c')
			TO_ADD = ft_ctostr((char)(va_arg(lst, int)));
	else
			TO_ADD = ft_strdup(va_arg(lst, char *));
	if (TO_ADD == NULL && ft_strchr("sS", TYPE))
		TO_ADD = ft_strdup("(null)");
	if (TO_ADD == NULL && ft_strchr("cC", TYPE))
		TO_ADD = ft_wtostr(0);

}
void	type_analyse(t_printf *data, int i, int j)
{
	SPEC = 0;
	while (j < i && SPEC == 0)
	{
		SCAN = ft_strndup(&(data->str[j]), i-j);
		if (data->str[j] == 'h')
			SPEC = (ft_strrchr(SCAN, 'h') != SCAN) ? 1 : 2;
		if (data->str[j] == 'l')
			SPEC = (ft_strrchr(SCAN, 'l') != SCAN) ? 4 : 3;
		if (data->str[j] == 'j')
			SPEC = 5;
		if (data->str[j] == 'z')
			SPEC = 6;
		j++;
	}
}

void	convert(t_printf *data, va_list lst, int i, int j)
{
	int base;

	SPEC = 0;
	TYPE = data->str[i - 1];
	base = (ft_strchr("oO", TYPE)) ? 8 : (base = (ft_strchr("xXp", TYPE)) ? 16 : 10);
	if (ft_strlen(SCAN = ft_strndup(&(data->str[j]), i-j)) > 1)
		type_analyse(data, i, j);
	if (TYPE == 's' || TYPE == 'S' || TYPE == 'c' || TYPE == 'C')
		store_cs(data, lst);
	else if (TYPE == 'd' || TYPE == 'i' || TYPE == 'D')
		store_di(data, lst);
	else if (ft_strchr("oOuUxXp", TYPE) != NULL)
		store_uoxp(data, lst, base);
	else if (TYPE == '%')
		TO_ADD = ft_strdup("%");
	flags(data, i, j);
	//data->result = ft_strjoinfree(data->result, TO_ADD);
	//data->result = ft_strjoin(data->result, TO_ADD);
	
	//ft_putendl("Voilà mon TO_ADD :");
	//ft_putendl(TO_ADD);
	//ft_putendl("Voilà mon data->result :");
	//ft_putendl(data->result);

	if (data->result == NULL)
		data->result = ft_strdup(TO_ADD);
	else
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
	ft_putnbr(SPEC);
	ft_putstr("\n");
	ft_putstr("\nVoilà mon TYPE :");
	ft_putchar(TYPE);
	ft_putstr("\nMon option base est égale à : ");
	ft_putnbr(base);
	ft_putstr("\n");
	*/
	/*
	ft_putstr("\nMon option d'analyse est égale à : ");
	ft_putnbr(SPEC);
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
