/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 05:14:00 by mwallis           #+#    #+#             */
/*   Updated: 2024/11/06 07:04:49 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int	ft_printf(const char *str, ...);
int	ft_printchar(int c);
int	ft_printstr(char *str);
int	ft_printptr(void *ptr);
int	ft_printnbr(int nb);
int	ft_printunsigned(unsigned int nb);
int	ft_printhexa(unsigned int nb, char c);

#endif
