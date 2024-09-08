/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduric <iduric@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:04:51 by iduric            #+#    #+#             */
/*   Updated: 2023/11/06 21:57:07 by iduric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*s3;

	i = 0;
	j = 0;
	s3 = malloc(sizeof(char const) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (s3);
	while (s1[j])
	{
		s3[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j])
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	return (s3);
}
/*
int main(void)
{
	char *s1 = "Bonjour les amis ";
	char *s2 = "je suis Ivan";

	printf("%s", ft_strjoin(s1, s2));
	return (0);
}*/
