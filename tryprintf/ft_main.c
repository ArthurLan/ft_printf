/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 19:21:30 by alanter           #+#    #+#             */
/*   Updated: 2018/05/23 15:55:28 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/includes/libftprintf.h"

int	main()
{
	int x;

	x = 20;
	//ft_printf("mon premier nombre est : %d,\n puis ma string est : '%s',\n et enfin mon dernier nombre est : %d", 42, "yoyoyo nega", 21);
	ft_printf("voilà ma phrase de test, j'insère un nombre ici : %hhd, j'écris ici un %%, et je termine avec un deuxieme nombre : %-#d.", 7, 8 + x, 7 + 8 + x + x);
	return (0);
}
