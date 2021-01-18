/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 10:25:03 by vazra             #+#    #+#             */
/*   Updated: 2021/01/18 10:55:13 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char		*ft_strdup(const char *s1)
{
	int				len;
	int				i;
	char			*s2;

	i = 0;
	len = ft_strlen(s1);
	s2 = malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

size_t		ft_strlen(const char *s)
{
	size_t			i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strchr(const char *s, int c)
{
	char			*ptr;

	ptr = (char *)s;
	while (*ptr != c)
	{
		if (*ptr == '\0')
			return (NULL);
		ptr++;
	}
	return (ptr);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*s2;
	unsigned int	i;
	size_t			j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	s2 = malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			s2[j] = s[i];
			j++;
		}
		i++;
	}
	s2[j] = '\0';
	return (s2);
}

static void	ft_fill(char *dst, char const *s, int *i)
{
	int			j;

	j = 0;
	while (s[j])
	{
		dst[*i] = s[j];
		j++;
		(*i)++;
	}
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char		*dst;
	int			i;

	if (!s1 || !s2)
		return (NULL);
	dst = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dst)
		return (NULL);
	i = 0;
	ft_fill(dst, s1, &i);
	ft_fill(dst, s2, &i);
	dst[i] = '\0';
	return (dst);
}
