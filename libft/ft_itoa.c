/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduric <iduric@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:21:12 by iduric            #+#    #+#             */
/*   Updated: 2024/08/29 16:31:04 by iduric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*revstr(char *str)
{
	char	temp;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < ft_strlen(str) / 2)
	{
		temp = str[i];
		str[i] = str[j - i];
		str[j - i] = temp;
		i++;
	}
	return (str);
}

int	numcnt(int n)
{
	int	nbr_size;

	nbr_size = 0;
	if (n < 0)
	{
		n = n * -1;
		nbr_size++;
	}
	while (n > 9)
	{
		nbr_size++;
		n = n / 10;
	}
	nbr_size++;
	return (nbr_size);
}

char	*ft_itoa(int n)
{
	char	*nb_en_char;
	size_t	i;
	int		number_size;

	number_size = numcnt(n);
	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	nb_en_char = malloc(sizeof(char) * numcnt(n) + 1);
	if (!nb_en_char)
		return (NULL);
	if (n < 0)
	{
		n = n * -1;
		nb_en_char[numcnt(n)] = 45;
	}
	while (n > 9)
	{
		nb_en_char[i++] = (n % 10) + 48;
		n = n / 10;
	}
	nb_en_char[i] = n + 48;
	nb_en_char[number_size] = '\0';
	return (revstr(nb_en_char));
}
/*
int	main(void)
{
	int test;

	test = 400;
	printf("%s", ft_itoa(test));

	return (0);
}*/