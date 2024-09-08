/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduric <iduric@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 04:31:41 by iduric            #+#    #+#             */
/*   Updated: 2023/12/18 22:45:35 by iduric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*hank;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	hank = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!hank)
		return (NULL);
	while (s[i])
	{
		hank[i] = f(i, s[i]);
		i++;
	}
	hank[i] = '\0';
	return (hank);
}
