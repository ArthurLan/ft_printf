/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 17:36:53 by alanter           #+#    #+#             */
/*   Updated: 2018/06/05 23:48:18 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
 * ** FLAG = gere la presence de flags
 * ** FLAG[0] = #;
 * ** FLAG[1] = +;
 * ** FLAG[2] = space;
 * ** FLAG[3] = -;
 * ** FLAG[4] = 0;
 * ** FLAG[5] = padding;
 * ** FLAG[6] = precision;
 * ** FLAG[7] = where add my 0;
 * */

void	scan_flag(t_printf *data)
{
		int state;

		state = 0;
		while (*SCAN != 0)
		{
			state = (state == 2 && *SCAN == '.') ? 3 : state;
			state = (*SCAN == '.' && state < 2) ? 2 : state;
			if (*SCAN == '#')
				FLAG[0] = 1;
			else if (*SCAN == '+')
				FLAG[1] = 1;
			else if (*SCAN == ' ')
				FLAG[2] = 1;
			else if (*SCAN == '-')
				FLAG[3] = 1;
			else if (state == 0 && *SCAN == '0')
				FLAG[4] = 1;
			else if (state == 0 && *SCAN > '0' && *SCAN <= '9' && (state = 1))
				FLAG[5] = ft_atoi(SCAN);
			else if (state == 2 && *SCAN > '0' && *SCAN <= '9' && (state = 3))
				FLAG[6] = ft_atoi(SCAN) != 0 ? ft_atoi(SCAN) : -1;
			SCAN++;
		}
		FLAG[6] = (((state == 2 || state == 3) && FLAG[6] == 0) ?
				-1 : FLAG[6]);
}

void	flag_char(t_printf *data)
{
	ft_putstr("\nflag char\n");
	ft_putstr(SCAN);
}

void	flag_int(t_printf *data)
{
	ft_putstr("\nflag int\n");
	ft_putstr(SCAN);
}

void	flags(t_printf *data, int i, int j)
{
	SCAN = ft_strndup(&(data->str[j]), i-j);
	data->flag = ft_memalloc(9);
	scan_flag(data);

	if (ft_strchr("cCsS", TYPE))
		flag_char(data);
	else if (ft_strchr("idDuUoOxXp", TYPE))
		flag_int(data);
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
