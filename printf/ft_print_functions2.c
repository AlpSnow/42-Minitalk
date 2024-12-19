/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_functions2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 03:41:18 by mwallis           #+#    #+#             */
/*   Updated: 2024/11/06 06:24:04 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_lenunsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		return (1);
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	ft_putunsigned(unsigned int n)
{
	char	c;

	if (n >= 10)
	{
		ft_putunsigned(n / 10);
	}
	n = n % 10;
	c = n + '0';
	write(1, &c, 1);
}

int	ft_printunsigned(unsigned int nb)
{
	int		len;

	len = ft_lenunsigned(nb);
	ft_putunsigned(nb);
	return (len);
}
