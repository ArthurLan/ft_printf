/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:18:36 by alanter           #+#    #+#             */
/*   Updated: 2018/06/22 21:32:23 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_is_flag(char c)
{
	if (ft_strchr(".0123456789#-+ hljz", c) != NULL)
		return (1);
	else
		return (0);
}

void	back_zero(t_printf *data, int len)
{
	if (CZERO > 0)
		BACKZ = (BACKZ > 0) ? BACKZ + CZERO : ft_strlen(RET) + CZERO;
	if (BACKZ > 0 && CZERO == 0)
		BACKZ += len;
	CZERO = 0;
}

void	store_cleanstr(t_printf *data, int i, int j)
{
	char *tmp;
	int		len;

	tmp = TO_ADD;
	TO_ADD = ft_strndup(&(data->str[j]), i - j);
	len = ft_strlen(TO_ADD);
	RET = ft_ultim_join(&RET, &TO_ADD, 3, BACKZ, 0);
	back_zero(data, len);
	if (tmp != NULL)
		free(tmp);
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
			if (data->str[i] != 0 && ft_strchr("sSpdDioOuUxXcC%", data->str[i]))
			{
				i++;
				convert(data, lst, i, j);
				back_zero(data, 0);
			}
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
	int			ret;

	data = ft_memalloc(sizeof(t_printf));
	data->str = ft_strdup(format);
	BACKZ = 0;
	CZERO = 0;
	va_start(lst, format);
	parsing(data, lst);
	if (BACKZ)
		write(1, RET, BACKZ);
	else
		ft_putstr(RET);
	ret = (BACKZ) ? BACKZ : ft_strlen(RET);
	if (RET)
		free(RET);
	if (data->str)
		free(data->str);
	va_end(lst);
	return (ret);
}
