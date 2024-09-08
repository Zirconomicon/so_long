/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduric <iduric@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:11:26 by iduric            #+#    #+#             */
/*   Updated: 2023/12/18 22:46:03 by iduric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*hs;

	i = 0;
	hs = (char *)haystack;
	if (*needle == '\0')
		return (hs);
	while (hs[i] && i < len)
	{
		j = 0;
		while (hs[i + j] == needle[j] && hs[i] && needle[j] && i + j < len)
		{
			j++;
			if (!needle[j])
				return (hs + i);
		}
		i++;
	}
	return (NULL);
}
