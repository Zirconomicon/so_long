/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsII.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduric <iduric@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:41:36 by iduric            #+#    #+#             */
/*   Updated: 2024/08/28 23:21:26 by iduric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lhexa(unsigned long long n)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n >= 16)
	{
		ft_lhexa(n / 16);
		ft_lhexa(n % 16);
	}
	else if (n < 16)
	{
		write(1, &hex[n], 1);
	}
	return (hexa_size(n));
}

int	ft_uhexa(unsigned long long n)
{
	char	*hex;

	hex = "0123456789ABCDEF";
	if (n >= 16)
	{
		ft_uhexa(n / 16);
		ft_uhexa(n % 16);
	}
	else if (n < 16)
	{
		write(1, &hex[n], 1);
	}
	return (hexa_size(n));
}

int	ft_putptr(void *ptr)
{
	int	size;

	write(1, "0x", 2);
	size = (ft_lhexa((unsigned long long)ptr));
	return (size + 2);
}

int	nbr_size(int n)
{
	int	size;

	size = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		size++;
	}
	while (n >= 10)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

int	size_of_unsigned_nbr(unsigned long long n)
{
	int	size;

	size = 1;
	/*if (n < 0)
		n = 4294967295 - n;*/
	while (n >= 10)
	{
		n = n / 10;
		size++;
	}
	return (size);
}
