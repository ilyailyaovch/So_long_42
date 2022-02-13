/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 15:54:51 by rtracee           #+#    #+#             */
/*   Updated: 2022/02/13 10:00:39 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_strdup(const char *s1)
{
	size_t	s;
	char	*s2;

	s = ft_strlen(s1);
	s2 = malloc(s + 1);
	if (s2 == NULL)
		return (NULL);
	s = 0;
	while (s1[s] != '\0')
	{
		s2[s] = s1[s];
		s++;
	}
	s2[s] = '\0';
	return (s2);
}

char	*ft_strchr(const char *s, int c)
{
	return (ft_memchr(s, c, ft_strlen(s) + 1));
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	UC		a;
	size_t	i;

	a = c;
	i = 0;
	while (i < n)
	{
		if (((UC *)s)[i] == a)
			return (((UC *)s) + i);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	int		b;
	char	*s3;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	a = 0;
	b = 0;
	s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s3 == NULL)
		return (NULL);
	while (a < ft_strlen(s1))
	{
		s3[a] = s1[a];
		a++;
	}
	while (b < ft_strlen(s2))
	{
		s3[a] = s2[b];
		b++;
		a++;
	}
	s3[a] = '\0';
	return (s3);
}

int	ft_out_gnl(int i, char **buf, char **remain)
{
	if (i && *remain)
	{
		ft_clear(buf);
		return (1);
	}
	if (!i)
	{
		ft_clear(buf);
		ft_clear(remain);
	}
	return (0);
}
