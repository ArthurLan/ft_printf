/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 16:53:16 by alanter           #+#    #+#             */
/*   Updated: 2017/12/03 16:57:19 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while ((ft_islower(str[i]) == 1 || ft_isupper(str[i]) == 1) && str != 0)
		i++;
	if (str[i] == 0)
		return (1);
	return (0);
}
