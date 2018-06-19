/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultim_join.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 16:26:32 by alanter           #+#    #+#             */
/*   Updated: 2018/06/19 20:23:06 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ** Écrire une fonction qui prend en paramètres deux strings, un int qui précisera les strings dont la mémoire sera à libérer, et deux autres int qui définiront le nombre de caractères à copier depuis leur string respectives. 
 * ** Dans le cas où ils seraient égaux à zero, le nombre de caractères à copier correspondra au nombre de caractères présents avant le premier \0.
 * **
 * ** La fonction devra allouer l'espace nécessaire à la string retournée en utilisant malloc.
 * **
 * ** Selon la valeur de memlib, la fonction devra à l'aide de free :
 * ** 0 -> ne pas libérer la mémoire
 * ** 1 -> libérer la mémoire de s1 uniquement
 * ** 2 -> libérer la mémoire de s2 uniquement
 * ** 3 -> libérer la mémoire de s1 et s2
 * **
 * ** Attention la fonction devra prendre en compte la possibilité qu'une string null soit passée en paramètre, et doit être capable de renvoyer une string si l'autre string n'est pas nulle.
 * **
 * ** La fonction ne devra en aucun cas libérer la mémoire d'une fonction nulle afin d'éviter une double libération.
 * **
 * ** Dans le cas où n1 et/ou n2 sont supérieur à 0, la fonction devra conserver la présence du \0 au sein de la string renvoyée, la valeur de n sera alors égale au nombre de caractères présents dans la string à copier contenant le \0.
 * */


	/*
	while (n1--)
	{
		d[i] = s1[i];
		i++;
	}
	while (s2[j] != 0)
	{
		d[i] = s2[j];
		i++;
		j++;
	}
	d[i] = 0;
	*/

char	*ft_strnjoin(char const *s1, char const *s2, int n1, int n2)
{
	char	*d;
	int		i;

	i = 0;
	//n1 = (n1 == 0) ? ft_strlen(s1) : n1;
	//n2 = (n2 == 0) ? ft_strlen(s2) : n2;
	if (!(d = (char *)ft_memalloc(n1 + n2 + 1)))
		return (NULL);
	while (n1--)
		d[i++] = *s1++;
	while (n2--)
		d[i++] = *s2++;
	return (d);
}

char *ft_sort_null(char *s1, char *s2, int n1, int n2)
{
	char *str;

	n1 = (n1 == 0) ? ft_strlen(s1) : n1;
	n2 = (n2 == 0) ? ft_strlen(s2) : n2;
	if (s1 && s2 == NULL)
		str = ft_strndup(s1, n1);
	else if (s1 == NULL && s2)
		str = ft_strndup(s2, n2);
	else if (s1 && s2)
		str = ft_strnjoin(s1, s2, n1, n2);
	else
		str = NULL;
	return (str);
}

char *ft_ultim_join(char **s1, char **s2, int memlib, int n1, int n2)
{
	char *str;
	
	str = ft_sort_null(*s1, *s2, n1, n2);
	if (*s1 != NULL && (memlib == 1 || memlib == 3))
	{
		free(*s1);
		*s1 = NULL;
	}
	if (*s2 != NULL && (memlib == 2 || memlib == 3))
	{
		free(*s2);
		*s2 = NULL;
	}
	return (str);
}
