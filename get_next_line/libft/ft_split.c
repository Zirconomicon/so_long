/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduric <iduric@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 22:44:26 by iduric            #+#    #+#             */
/*   Updated: 2023/12/18 22:44:30 by iduric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	wrdln(char const *s, char c)
{
	int	ln;

	ln = 0;
	while (s[ln] && s[ln] != c)
		ln++;
	return (ln);
}

char	*shink(char const *s, char c)
{
	char	*subs;
	int		i;
	int		j;

	j = 0;
	i = 0;
	subs = malloc(sizeof(char) * (wrdln(s, c) + 1));
	if (!subs)
		return (NULL);
	while (s[i] && s[i] != c)
		subs[j++] = s[i++];
	subs[j] = 0;
	return (subs);
}

int	cntwrd(char const *s, char c)
{
	int	binks;
	int	i;

	i = 0;
	binks = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			binks++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (binks);
}

char	**ft_split(char const *s, char c)
{
	char	**ans;
	int		i;

	if (!s)
		return (NULL);
	ans = malloc(sizeof(char *) * (cntwrd(s, c) + 1));
	if (!ans)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			ans[i++] = shink(s, c);
		while (*s && *s != c)
			s++;
	}
	ans[i] = 0;
	return (ans);
}
