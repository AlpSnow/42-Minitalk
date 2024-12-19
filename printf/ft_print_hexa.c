/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 06:55:18 by mwallis           #+#    #+#             */
/*   Updated: 2024/11/07 22:30:42 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_lenhexa(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		return (1);
	}
	while (n > 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

static void	ft_puthexa(unsigned int n, char convert)
{
	char	c;

	if (n >= 16)
	{
		ft_puthexa((n / 16), convert);
	}
	n = n % 16;
	if (n > 9)
	{
		if (convert == 'x')
			c = n - 10 + 'a';
		else
			c = n - 10 + 'A';
	}
	else
	{
		c = n + '0';
	}
	write(1, &c, 1);
}

int	ft_printhexa(unsigned int nb, char convert)
{
	int	len;

	len = ft_lenhexa(nb);
	ft_puthexa(nb, convert);
	return (len);
}
