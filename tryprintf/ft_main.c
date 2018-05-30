/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 19:21:30 by alanter           #+#    #+#             */
/*   Updated: 2018/05/30 17:09:30 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/includes/libftprintf.h"
#include <stdio.h>

int	main()
{
	int x;

	x = 20;
	//ft_printf("mon premier nombre est : %d,\n puis ma string est : '%s',\n et enfin mon dernier nombre est : %d", 42, "yoyoyo nega", 21);
	//ft_printf("voilà ma phrase de test, j'insère un nombre avec pourcentage  ici : %hhd%%, et je termine avec un deuxieme nombre : %-d.\n Ici j'affiche même une phrase : \"%s\"", 7, 300, "ça avance bien tout ça !");
	ft_printf("%p", &x);
	printf("\n");
	printf("\n");
	printf("%p", &x);
	//printf("voilà ma phrase de test, j'insère un nombre avec pourcentage  ici : %x%%, et je termine avec un deuxieme nombre : %-d.\n Ici j'affiche même une phrase : \"%s\"", 4294967296, 300, "ça avance bien tout ça !");
	return (0);
}
