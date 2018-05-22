/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 18:43:17 by alanter           #+#    #+#             */
/*   Updated: 2018/05/22 15:23:33 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*penser à la lecture du va_arg dans un autre fichier :
 * fonctionne comme une variable statique ? ou stack ?
*/

void	store_nbr(t_printf *data, int i)//, int j)
{
	char	to_add[2];

	to_add[0] = data->str[i];
	to_add[1] = 0;
	data->result = ft_strjoin(data->result, to_add);
}

void	convert(t_printf *data, va_list lst, int i, int j)
{
	store_nbr(data, i);
	j++;
	lst++;
}
