/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                             :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: iduric <iduric@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:29:53 by iduric            #+#    #+#             */
/*   Updated: 2024/02/27 09:51:29 by iduric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	a;

	a = n;
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-n);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else if (n < 10)
	{
		n = n + '0';
		write(1, &n, 1);
	}
	return (nbr_size(a));
}

int	ft_put_unsigned_nbr(unsigned int n)
{
	unsigned int	a;

	a = n;
	if (n >= 10)
	{
		ft_put_unsigned_nbr(n / 10);
		ft_put_unsigned_nbr(n % 10);
	}
	else if (n < 10)
	{
		n = n + '0';
		write(1, &n, 1);
	}
	return (size_of_unsigned_nbr(a));
}

int	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_percent(void)
{
	write(1, "%", 1);
	return (1);
}
