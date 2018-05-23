/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:18:36 by alanter           #+#    #+#             */
/*   Updated: 2018/05/22 16:26:41 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_is_flag(char c)
{
	if (ft_strchr("#0-+hljz", c) != NULL)
		return (1);
	else
		return (0);
}

void	store_cleanstr(t_printf *data, int i, int j)
{
	char	*to_add;

	to_add = ft_strndup(&(data->str[j]), i - j);
	data->result = ft_strjoin(data->result, to_add);
}

/*
 * Fonction en charge du contenu
 *
 * Store les différentes parties dans le result
 *
 * retourne le result à ft_printf
*/

void parsing(t_printf *data, va_list lst)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while(data->str[i] != 0)
	{
		j = i;
		while(data->str[i] != '%' && data->str[i] != 0)
			i++;
		if (i != j)
			store_cleanstr(data, i, j);
		if (data->str[i] == '%')
		{
			i++;
			j = i;
			while (data->str[i] != 0 && ft_is_flag(data->str[i]))
				i++;
			i++;
			convert(data, lst, i, j);
		}
	}
}


/*		Initialise la struct contenant :
 * la str 'format'
 * le resultat final à print
 * les delimiteurs des arguments au sein de format
 *
 * 		Initialise la va_list, pour gérer les arguments de la fct variadique
 * 
 *		Renvoie vers la fonction en charge de gérer le contenu de format
 *
 * 		Retourne la taille du resultat final
*/

int	ft_printf(const char *format, ...)
{
	va_list lst;
	t_printf *data;

	data = ft_memalloc(sizeof(t_printf));
	data->str = ft_strdup(format);
	CAST = ft_memalloc(18);
	va_start(lst, format);
	data->result = ft_memalloc(1);
	parsing(data, lst);
	/* pour fonction de gestion du flag
	s = va_arg(ap, char *);
	*/
	ft_putstr(data->result);
	return (0);
}
