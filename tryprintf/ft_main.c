/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 19:21:30 by alanter           #+#    #+#             */
/*   Updated: 2018/06/08 14:09:21 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/includes/libftprintf.h"
#include <stdio.h>
#include <limits.h>

int	main()
{
	short sh;
	//int x;
	//unsigned long long y;

	sh = 49;
	//x = 20;
	//y = 18446744073709551615;

	//ft_printf("mon premier nombre est : %d,\n puis ma string est : '%s',\n et enfin mon dernier nombre est : %d", 42, "yoyoyo nega", 21);
	//ft_printf("voilà ma phrase de test, j'insère un nombre avec pourcentage  ici : %hhd%%, et je termine avec un deuxieme nombre : %-d.\n Ici j'affiche même une phrase : \"%s\"", 7, 300, "ça avance bien tout ça !");
	//printf("voilà ma phrase de test, j'insère un nombre avec pourcentage  ici : %x%%, et je termine avec un deuxieme nombre : %-d.\n Ici j'affiche même une phrase : \"%s\"", 4294967296, 300, "ça avance bien tout ça !");

	/*
	ft_printf("p ft_printf : %p", &x);
	printf("\n");
	printf("p printf : %p", &x);
	printf("\n");
	printf("\n");
	ft_printf("o ft_printf : %o", 42);
	printf("\n");
	printf("o printf : %o", 42);
	printf("\n");
	printf("\n");
	ft_printf("u ft_printf : %u", 171);
	printf("\n");
	printf("u printf : %lld", 1855571562067968);
	printf("\n");
	printf("\n");
	ft_printf("u ft_printf : %d", 42);
	printf("\n");
	printf("u printf : %#x", 42);
	*/
	/* Problème affiche quand même le nombre
	printf("\n vrai printf : test %.", sh);
	printf("\n");
	ft_printf("\n mon ft_printf : test %.", sh);
	*/
	//printf("\n vrai printf : test %.3d", sh);
	//printf("\n");
	//ft_printf("\n mon ft_printf : test %.3d", sh);
	//ft_printf("\nmon ft_printf : test %ld", LONG_MIN);
	//printf("\nprintf : test %ld", LONG_MIN);
	
	/*
	printf("   printf : test -%p-\n", &sh);
	ft_printf("ft_printf : test -%p-\n", &sh);
	printf("   printf #o: test %#O\n", 0);
	ft_printf("ft_printf #o: test %#O\n", 0);
	printf("   printf %% -4d: test -% -4d-\n", 25);
	ft_printf("ft_printf %% -4d: test -% -4d-\n", 25);
	printf("   printf %% d: test -% .4d-\n", 200);
	ft_printf("ft_printf %% d: test -% .4d-\n", 200);

	printf("\n----- precision, largeur de champs, 0, # et x -----\n");
	ft_printf("ft_printf #09x : test_%#09x_test\n", 10);
	printf("   printf #09x : test_%#09x_test\n", 10);
	ft_printf("ft_printf #9x : test_%#9x_test\n", 10);
	printf("   printf #9x : test_%#9x_test\n", 10);
	ft_printf("ft_printf #.9x : test_%#.9x_test\n", 10);
	printf("   printf #.9x : test_%#.9x_test\n", 10);
	ft_printf("ft_printf #9.x : test_%#9.10x_test\n", 10);
	printf("   printf #9.x : test_%#9.10x_test\n", 10);

	printf("\n----- precision, largeur de champs, 0, # et o -----\n");
	ft_printf("ft_printf #09o : test_%#09o_test\n", 10);
	printf("   printf #09o : test_%#09o_test\n", 10);
	ft_printf("ft_printf #9o : test_%#9o_test\n", 10);
	printf("   printf #9o : test_%#9o_test\n", 10);
	ft_printf("ft_printf #.9o : test_%#.9o_test\n", 10);
	printf("   printf #.9o : test_%#.9o_test\n", 10);
	ft_printf("ft_printf #9.o : test_%#9.10o_test\n", 10);
	printf("   printf #9.o : test_%#9.10o_test\n", 10);

	printf("\n----- precision, largeur de champs, et s -----\n");
	printf("   printf #09x : test_%.9s_test\n", "||ma string||" );
	return (0);
	*/

	ft_printf("ft_printf : %ld\n", 4294959296);
	printf("   printf : %ld\n", 4294959296);
	ft_printf("ft_printf : -%08s-\n", "t1");
	printf("   printf : -%08s-\n", "t1");
}
