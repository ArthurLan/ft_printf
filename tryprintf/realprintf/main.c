/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 17:32:15 by alanter           #+#    #+#             */
/*   Updated: 2018/06/05 23:39:16 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main()
{
	unsigned char uc;
	unsigned short us;
	unsigned long ul;
	unsigned long long c;

	uc = 42;
	us = 420;
	ul = 42000000000000;
	c = 18446744073709551615;
	printf("\n----- TEST PRINTF -----\n");
	printf("\n----- TEST d -----\n");
	printf("Seul : %d\n", 42);

	printf("\n----- flags #0-+' ' -----\n");
	printf("# : %#d\n", 42);
	printf("09 : test_%09d_test\n", 42);
	printf("'3'0 : test_%3d_test\n", 42);
	printf("-'3' : test_%-3d_test\n", 42);
	printf("+ : test_%+d_test\n", 42);
	printf("+ : test_%+d_test\n", -42);
	printf("' '9 : test_% 9d_test\n", 42);
	printf("-' ' : test_%- d_test\n", 42);
	printf("-' '9 : test_%- 9d_test\n", 42);

	printf("\n----- précision et flag 0-----\n");
	printf(".9 : test_%.9d_test\n", 42);
	printf("09 : test_%09d_test\n", 42);
	printf("-.9 : test_%-.9d_test\n", 42);
	printf("-09 : test_%-09d_test\n", 42);
	printf(".-9 : test_%.-9d_test\n", 42);
	printf("0-9 : test_%0-9d_test\n", 42);

	printf("\n----- largeur de champ -----\n");
	printf("9 : test_%9d_test\n", 42);

	printf("\n----- précision et flag +-----\n");
	printf("+ : test_%+d_test\n", -42);

	printf("\n----- precision, flag + et nombre neg-----\n");
	printf("09 : test_%09d_test\n", -42);

	printf("\n----- convertisseur de longueur -----\n");
	printf("ld : test_%090ld_test\n", -4299999999999999);
	printf("\n\nAAAAAAAAAAAAAAAAAAA d : test_%d_test\n", (unsigned long long)223372036854775807);
	printf("\n\n\nlld : test_%l 100u_test\n", c);

	printf("\n----- convertisseur de longueur hh -----\n");
	printf("hh : test_%hhd_test\n", 42890);

	printf("\n----- plusieurs convertisseurs de longueur -----\n");
	printf("hz : test_%zhd_test\n", 42);

	printf("\n----- Convertisseur de longueur sur plusieurs delim -----\n");
	printf("hho : test_%hho_test\n", uc);
	printf("hhu : test_%hhu_test\n", uc);
	printf("hhx : test_%hhx_test\n", uc);
	printf("ho : test_%ho_test\n", us);
	printf("hu : test_%hu_test\n", us);
	printf("hx : test_%hx_test\n", us);
	printf("lo : test_%lo_test\n", ul);
	printf("lu : test_%lu_test\n", ul);
	printf("lx : test_%lx_test\n", ul);

	printf("\n----- precision, largeur de champs, 0, # et x -----\n");
	printf("09#x : test_%09#x_test\n", 10);
	printf("#09x : test_%#09x_test\n", 10);
	printf("9#x : test_%9#x_test\n", 10);
	printf("#9x : test_%#9x_test\n", 10);
	printf(".9#x : test_%.9#x_test\n", 10);
	printf("#.9x : test_%#.9x_test\n", 10);
	printf("#9.x : test_%#9.x_test\n", 10);

	printf("\n----- precision, largeur de champs, 0, sans # et x -----\n");
	printf("09x : test_%09x_test\n", 10);
	printf("09x : test_%09x_test\n", 10);
	printf("9x : test_%9x_test\n", 10);
	printf("9x : test_%9x_test\n", 10);
	printf(".9x : test_%.9x_test\n", 10);
	printf(".9x : test_%.9x_test\n", 10);
	printf("9.x : test_%9.x_test\n", 10);

	printf("\n----- precision et - -----\n");
	printf("-.9 : test_%-.9d_test\n", 42);


	int q;

	q = 129;
	printf("%d", q);
	return (0);
}
