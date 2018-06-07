/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 17:36:53 by alanter           #+#    #+#             */
/*   Updated: 2018/06/07 22:28:40 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
 * ** FLAG = tab of int to deal with flags 
 * ** FLAG[0] = #;
 * ** FLAG[1] = +;
 * ** FLAG[2] = space;
 * ** FLAG[3] = -;
 * ** FLAG[4] = 0;
 * ** FLAG[5] = width;
 * ** FLAG[6] = precision;
 * ** FLAG[7] = where add my 0;
 * */

void	scan_flag(t_printf *data, char *scan)
{
		int state;

		state = 0;
		while (*scan != 0)
		{
			state = (state == 2 && *scan == '.') ? 3 : state;
			state = (*scan == '.' && state < 2) ? 2 : state;
			if (*scan == '#')
				FLAG[0] = 1;
			else if (*scan == '+')
				FLAG[1] = 1;
			else if (*scan == ' ' && (ft_strchr(SCAN, '+') == NULL))
				FLAG[2] = 1;
			else if (*scan == '-')// && (FLAG[4] = 0))
				FLAG[3] = 1;
			else if (state == 0 && *scan == '0' && (ft_strchr(SCAN, '-') == NULL))
				FLAG[4] = 1;
			else if (state == 0 && *scan > '0' && *scan <= '9' && (state = 1))
				FLAG[5] = ft_atoi(scan);
			else if (state == 2 && *scan > '0' && *scan <= '9' && (state = 3))
				FLAG[6] = ft_atoi(scan) != 0 ? ft_atoi(scan) : -1;
			scan++;
		}
		FLAG[6] = (((state == 2 || state == 3) && FLAG[6] == 0) ?
				-1 : FLAG[6]);
}

void	flag_char(t_printf *data)
{
	//ft_putstr("\nflag char\n");
	ft_putstr(SCAN);
}

void	flag_int(t_printf *data)
{
	char *flag;

	flag = NULL;
	if (FLAG[6] > 0 && FLAG[6] > (int)ft_strlen(TO_ADD))
	{
			flag = ft_memalloc(FLAG[6] - ft_strlen(TO_ADD) + 1);
			flag = ft_memset(flag, '0', FLAG[6] - ft_strlen(TO_ADD));
			TO_ADD = ft_strjoin(flag, TO_ADD);
	}
	//Créer une fonction ft_strjoinfree_a
	//Créer une fonction ft_strjoinfree_b
	if ((FLAG[0] == 1 && (TYPE == 'x' || TYPE == 'X')) || TYPE == 'p')
			TO_ADD = ft_strjoin("0x", TO_ADD);
	if (TYPE == 'X')
			ft_strupcase(TO_ADD);
	if (FLAG[0] == 1 && (TYPE == 'o' || TYPE == 'O'))
			TO_ADD = ft_strjoin("0", TO_ADD);
	if (FLAG[1] == 1 && ft_strchr("idD", TYPE) && (ft_atoi(TO_ADD) >= 0))
		TO_ADD = ft_strjoin("+", TO_ADD);
	if (FLAG[2] == 1 && ft_strchr("idD", TYPE) && (ft_atoi(TO_ADD) >= 0))
		TO_ADD = ft_strjoin(" ", TO_ADD);
	
	if (FLAG[5] > 0 && FLAG[5] > (int)ft_strlen(TO_ADD))
	{
		flag = ft_memalloc(FLAG[5] - ft_strlen(TO_ADD) + 1);
		flag = ft_memset(flag, ' ', FLAG[5] - ft_strlen(TO_ADD));
		TO_ADD = (FLAG[3] == 0) ? ft_strjoin(flag, TO_ADD) : ft_strjoin(TO_ADD, flag);
	}
	
}

void	flags(t_printf *data, int i, int j)
{

	SCAN = ft_strndup(&(data->str[j]), i-j);
	FLAG = ft_memalloc(sizeof(int) * 8);
	if (ft_strlen(SCAN) > 1 || TYPE == 'p')
	{
		scan_flag(data, SCAN);
		if (ft_strchr("cCsS", TYPE))
			flag_char(data);
		else if (ft_strchr("idDuUoOxXp", TYPE))
			flag_int(data);
	}
}

/*
	ft_putstr("\n\nVoilà ma précision :");
	ft_putnbr(size_end);
	ft_putstr("\n");



	ft_putstr("\n");
	ft_putstr("le test du début des flags :");
	ft_putstr(SCAN);
	ft_putstr("\n");
	*/
/*
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

	if (ft_strchr(SCAN, '.'))
		precision(data);
}
*/

/*
	int k;

	k = 0;
	while (k++ < 8)
	{
		ft_putstr("option[");
		ft_putnbr(k);
		ft_putstr("] = ");
		ft_putnbr(data->flag[k]);
		ft_putstr("\n");

	}
	*/
