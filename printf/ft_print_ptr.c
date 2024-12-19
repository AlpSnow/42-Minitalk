/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 22:52:08 by mwallis           #+#    #+#             */
/*   Updated: 2024/11/05 05:08:54 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_lenptr(uintptr_t address)
{
	int	len;

	len = 0;
	while (address > 0)
	{
		address = address / 16;
		len++;
	}
	return (len);
}

static void	ft_putptr(uintptr_t address)
{
	char	c;

	if (address >= 16)
	{
		ft_putptr(address / 16);
	}
	address = address % 16;
	if (address > 9)
		c = address + 'a' - 10;
	else
		c = address + '0';
	write(1, &c, 1);
}

int	ft_printptr(void *ptr)
{
	int	len;

	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	len = 2;
	ft_putptr((uintptr_t)ptr);
	len += ft_lenptr((uintptr_t)ptr);
	return (len);
}
