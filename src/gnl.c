/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 15:49:44 by rtracee           #+#    #+#             */
/*   Updated: 2022/02/13 09:28:06 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_gnl_in_line(char **line, char **str, char **gnl)
{
	char	*tmp;

	if (*gnl)
	{
		*str = ft_strchr(*gnl, '\n');
		if (*str)
		{
			**str = '\0';
			tmp = *line;
			*line = ft_strdup(*gnl);
			ft_clear(&tmp);
			(*str)++;
			tmp = *gnl;
			*gnl = ft_strdup(*str);
			ft_clear(&tmp);
		}
		else
		{
			tmp = *line;
			*line = ft_strdup(*gnl);
			ft_clear(&tmp);
			ft_clear(gnl);
		}
	}
}

void	ft_gnl_in_str(char **buf, char **str, char **gnl)
{
	*str = ft_strchr(*buf, '\n');
	if (*str)
	{
		**str = '\0';
		(*str)++;
		*gnl = ft_strdup(*str);
	}
}

char	*ft_g_n_l(int fd, char **line)
{
	static char	*gnl;
	char		*buf;
	int			i;
	char		*str;
	char		*tmp;

	buf = malloc(2);
	i = 1;
	str = NULL;
	*line = ft_strdup("");
	ft_gnl_in_line(line, &str, &gnl);
	while (!str && i > 0)
	{
		i = read(fd, buf, 1);
		buf[i] = '\0';
		ft_gnl_in_str(&buf, &str, &gnl);
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		ft_clear(&tmp);
	}
	i = ft_out_gnl(i, &buf, &gnl);
	return (*line);
}

int	ft_gnl(int fd, char **line)
{
	int			i;
	static char	*gnl;
	char		*buf;
	char		*str;
	char		*tmp;

	if (fd < 0 || !line || (read(fd, 0, 0) == -1))
		return (-1);
	buf = malloc(2);
	if (buf == NULL)
		return (-1);
	i = 1;
	str = NULL;
	*line = ft_strdup("");
	ft_gnl_in_line(line, &str, &gnl);
	while (!str && i > 0)
	{
		i = read(fd, buf, 1);
		buf[i] = '\0';
		ft_gnl_in_str(&buf, &str, &gnl);
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		ft_clear(&tmp);
	}
	return (ft_out_gnl(i, &buf, &gnl));
}
