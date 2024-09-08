/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduric <iduric@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:14:43 by iduric            #+#    #+#             */
/*   Updated: 2024/02/27 09:13:01 by iduric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_tamis(char conv, va_list etc)
{
	if (conv == 'c')
		return (ft_putchar(va_arg(etc, int)));
	else if (conv == 's')
		return (ft_putstr(va_arg(etc, char *)));
	else if (conv == 'p')
		return (ft_putptr(va_arg(etc, void *)));
	else if (conv == 'd' || conv == 'i')
		return (ft_putnbr(va_arg(etc, int)));
	else if (conv == 'u')
		return (ft_put_unsigned_nbr(va_arg(etc, unsigned int)));
	else if (conv == 'x')
		return (ft_lhexa(va_arg(etc, unsigned int)));
	else if (conv == 'X')
		return (ft_uhexa(va_arg(etc, unsigned int)));
	else if (conv == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *conv, ...)
{
	int		i;
	va_list	etc;

	i = 0;
	va_start(etc, conv);
	if (!conv)
		return (-1);
	while (*conv)
	{
		if (*conv == '%')
		{
			if (conv[1] == 'c' || conv[1] == 's' || conv[1] == 'p'
				|| conv[1] == 'd' || conv[1] == 'i' || conv[1] == 'u'
				|| conv[1] == 'x' || conv[1] == 'X' || conv[1] == '%')
				i += ft_tamis(*(++conv), etc);
		}
		else
			i += write(1, conv, 1);
		conv++;
	}
	return (i);
}
