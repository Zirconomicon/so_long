/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduric <iduric@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:21:12 by iduric            #+#    #+#             */
/*   Updated: 2023/12/18 22:15:06 by iduric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>
/*
int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str)
	{
		i++;
	}
	return (i);
}
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*subs;
	unsigned int	frank;

	frank = ft_strlen(s);
	i = 0;
	if (start > frank)
	{
		subs = malloc(sizeof(char));
		subs[i] = 0;
		return (subs);
	}
	if (!s)
		return (NULL);
	if (len > frank - start)
		len = frank - start;
	subs = (char *)malloc(len + 1);
	if (!subs)
		return (NULL);
	while (i < len)
		subs[i++] = s[start++];
	subs[i] = 0;
	return (subs);
}
/*
void	strwr(char *str)
{
	int	i;

	i = 0;
	while (str)
	{
		write(1, &str[i], 1);
		i++;
	}
	return ;
}

int	main(void)
{
	char *str = "Bonjour gromo";
	printf("%s\n", ft_substr(str, 0, 9));
	return (0);
}*/
