/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 17:36:53 by alanter           #+#    #+#             */
/*   Updated: 2018/06/01 20:45:50 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	precision(t_printf *data)
{
	char 	*prec;
	int		size_nb;
	int		size_end;

	size_nb = ft_strlen(TO_ADD);
	size_end = ft_atoi(ft_strchr(SCAN, '.') + 1);
	prec = NULL;
	if (TYPE == 's' || TYPE == 'S')
		;
	else if (size_end > size_nb)
		{
			prec = ft_memalloc(size_end - size_nb + 1);
			prec = ft_memset(prec, '0', size_end - size_nb);
			TO_ADD = ft_strjoin(prec, TO_ADD);
		}
}

void	flags(t_printf *data, int i, int j)
{
	SCAN = ft_strndup(&(data->str[j]), i-j);

	ft_putstr("\n");
	ft_putstr("le test du début des flags :");
	ft_putstr(SCAN);
	ft_putstr("\n");

	if (ft_strchr(SCAN, '.'))
		precision(data);
}

/*
	ft_putstr("\n\nVoilà ma précision :");
	ft_putnbr(size_end);
	ft_putstr("\n");
	*/
