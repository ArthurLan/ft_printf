/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:18:36 by alanter           #+#    #+#             */
/*   Updated: 2018/04/23 17:29:31 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list ap;
	int d;
	char c, *s;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			switch(*++format) {
			case 's':                      
					s = va_arg(ap, char *);
					//printf("string %s\n", s);
					ft_putstr(s);
					break;
			case 'd':                       /* int */
					d = va_arg(ap, int);
					ft_putnbr(d);
					break;
			case 'c': 
					c = va_arg(ap, int);
					//printf("char %c\n", c);
					ft_putchar(c);
					break;
			}
	     }
		else
			ft_putchar(*format);
		format++;
	}
	return (0);
}
