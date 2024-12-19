/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 23:21:32 by mwallis           #+#    #+#             */
/*   Updated: 2024/11/07 22:50:23 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_printvariable(char c, va_list arg)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_printchar(va_arg(arg, int));
	else if (c == 's')
		len = ft_printstr(va_arg(arg, char *));
	else if (c == 'p')
		len = ft_printptr(va_arg(arg, void *));
	else if (c == 'd' || c == 'i')
		len = ft_printnbr(va_arg(arg, int));
	else if (c == 'u')
		len = ft_printunsigned(va_arg(arg, unsigned int));
	else if (c == 'x' || c == 'X')
		len = ft_printhexa(va_arg(arg, unsigned int), c);
	else if (c == '%')
	{
		len = 1;
		write(1, "%", 1);
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	lstargs;
	int		i;
	int		len;

	if (str == NULL)
		return (-1);
	i = 0;
	len = 0;
	va_start(lstargs, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			len = len + ft_printvariable(str[i + 1], lstargs);
			i = i + 2;
		}
		else
		{
			len = len + ft_printchar(str[i]);
			i++;
		}
	}
	va_end(lstargs);
	return (len);
}
