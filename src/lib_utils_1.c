/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liba1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:17:55 by rtracee           #+#    #+#             */
/*   Updated: 2022/02/13 10:04:03 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_putstr(char *s)
{
	int	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_kolvo(int n)
{
	int		i;
	long	s;

	i = 0;
	s = n;
	if (s < 0)
	{
		s *= -1;
		i++;
	}
	while (s >= 10)
	{
		s /= 10;
		i++;
	}
	return (i + 1);
}

char	*ft_itoa(int n)
{
	char	*sar;
	int		a;
	long	b;

	b = n;
	a = ft_kolvo(b);
	sar = malloc(ft_kolvo(b) + 1);
	if (sar == NULL)
		return (NULL);
	if (n < 0)
		sar[0] = '-';
	if (b < 0)
		b = -b;
	sar[a] = '\0';
	a--;
	while (b >= 10)
	{
		sar[a] = b % 10 + 48;
		b /= 10;
		a--;
	}
	sar[a] = b % 10 + 48;
	return (sar);
}

int	ft_strlen(const char *s)
{
	int	c;

	c = 0;
	while (s[c] != '\0')
		c++;
	return (c);
}
