/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_create_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:47:48 by rtracee           #+#    #+#             */
/*   Updated: 2022/02/13 10:41:06 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_height(char *map)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(map, O_RDONLY, 0);
	while (ft_gnl(fd, &line) > 0)
	{
		free(line);
		height++;
	}
	close(fd);
	free(line);
	return (height);
}

int	ft_width(char *map)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(map, O_RDONLY, 0);
	ft_gnl(fd, &line);
	width = ft_strlen(line);
	free(line);
	while (ft_gnl(fd, &line) > 0)
	{
		if (ft_strlen(line) != width)
		{
			free(line);
			return (-1);
		}
		free(line);
	}
	if (ft_strlen(line) != width)
	{
		free(line);
		return (-1);
	}
	close(fd);
	free(line);
	return (width);
}

void	ft_init_image(t_data *data)
{
	data->step = 0;
	data->done = 0;
	data->p = 0;
	data->c = 0;
	data->e = 0;
	data->back_img = "sprite/back.xpm";
	data->player_r_img = "sprite/player_r.xpm";
	data->wall_img = "sprite/wall.xpm";
	data->exit_img = "sprite/exit.xpm";
	data->collect_img = "sprite/collect.xpm";
}

int	ft_key_exit(t_data *data)
{
	(void)data;
	exit (0);
}
