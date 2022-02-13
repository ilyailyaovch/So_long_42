/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:53:50 by rtracee           #+#    #+#             */
/*   Updated: 2022/02/13 11:08:40 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_back(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->back = mlx_xpm_file_to_image(data->mlx,
			data->back_img, &data->i_w, &data->i_h);
	while (i <= data->height)
	{
		j = 0;
		while (j < data->width)
		{
			mlx_put_image_to_window(data->mlx,
				data->window, data->back, j * 50, i * 50);
			j++;
		}
		i++;
	}
}

void	ft_wall(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->wall = mlx_xpm_file_to_image(data->mlx,
			data->wall_img, &data->i_w, &data->i_h);
	while (i <= data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx,
					data->window, data->wall, j * 50, i * 50);
			j++;
		}
		i++;
	}
}

void	ft_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->player_r = mlx_xpm_file_to_image(data->mlx,
			data->player_r_img, &data->i_w, &data->i_h);
	while (i <= data->height)
	{
		while (j < data->width)
		{
			if (data->map[i][j] == 'P')
			{
				mlx_put_image_to_window(data->mlx,
					data->window, data->player_r, j * 50, i * 50);
				data->player_x = j;
				data->player_y = i;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_collect(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->is_col = data->c;
	data->collect = mlx_xpm_file_to_image(data->mlx,
			data->collect_img, &data->i_w, &data->i_h);
	while (i <= data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx,
					data->window, data->collect, j * 50, i * 50);
			j++;
		}
		i++;
	}
}

void	ft_exit(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->exit = mlx_xpm_file_to_image(data->mlx,
			data->exit_img, &data->i_w, &data->i_h);
	while (i <= data->height)
	{
		j = 0;
		while (j <= data->width)
		{
			if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx,
					data->window, data->exit, j * 50, i * 50);
			j++;
		}
		i++;
	}
}
