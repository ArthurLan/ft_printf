/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printbase.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 19:42:39 by alanter           #+#    #+#             */
/*   Updated: 2018/05/01 20:41:40 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../1printf/includes/libftprintf.h"

void	putnbr_base(long nbr, int base)
{
	if (nbr > base)
	{
		putnbr_base(nbr / base, base);
		putnbr_base(nbr % base, base);
	}
	else
	{
		if (nbr < 10)
			ft_putnbr(nbr);
		else
			ft_putchar('a' + nbr - 10);
	}
}
