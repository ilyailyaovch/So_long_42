/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 20:09:08 by rtracee           #+#    #+#             */
/*   Updated: 2022/02/13 11:15:05 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_go_left(t_data *data, int i, int j)
{
	data->step = ft_step(data);
	mlx_put_image_to_window(data->mlx,
		data->window, data->back, j * 50 - 50, i * 50);
	mlx_put_image_to_window(data->mlx,
		data->window, data->back, j * 50, i * 50);
	mlx_put_image_to_window(data->mlx,
		data->window, data->player_r, j * 50 - 50, i * 50);
	data->player_x = j - 1;
	data->player_y = i;
	if (data->map[i][j - 1] == 'C' && data->is_col > 0)
	{
		data->is_col--;
		data->map[i][j - 1] = '0';
	}
}

void	ft_go_right(t_data *data, int i, int j)
{
	data->step = ft_step(data);
	mlx_put_image_to_window(data->mlx,
		data->window, data->back, j * 50 + 50, i * 50);
	mlx_put_image_to_window(data->mlx,
		data->window, data->back, j * 50, i * 50);
	mlx_put_image_to_window(data->mlx,
		data->window, data->player_r, j * 50 + 50, i * 50);
	data->player_x = j + 1;
	data->player_y = i;
	if (data->map[i][j + 1] == 'C' && data->is_col > 0)
	{
		data->is_col--;
		data->map[i][j + 1] = '0';
	}
}

void	ft_go_up(t_data *data, int i, int j)
{
	data->step = ft_step(data);
	mlx_put_image_to_window(data->mlx,
		data->window, data->back, j * 50, i * 50 - 50);
	mlx_put_image_to_window(data->mlx,
		data->window, data->back, j * 50, i * 50);
	mlx_put_image_to_window(data->mlx,
		data->window, data->player_r, j * 50, i * 50 - 50);
	data->player_x = j;
	data->player_y = i - 1;
	if (data->map[i - 1][j] == 'C' && data->is_col > 0)
	{
		data->is_col--;
		data->map[i - 1][j] = '0';
	}
}

void	ft_go_down(t_data *data, int i, int j)
{
	data->step = ft_step(data);
	mlx_put_image_to_window(data->mlx,
		data->window, data->player_r, j * 50, i * 50 + 50);
	mlx_put_image_to_window(data->mlx,
		data->window, data->back, j * 50, i * 50);
	mlx_put_image_to_window(data->mlx,
		data->window, data->player_r, j * 50, i * 50 + 50);
	data->player_x = j;
	data->player_y = i + 1;
	if (data->map[i + 1][j] == 'C' && data->is_col > 0)
	{
		data->is_col--;
		data->map[i + 1][j] = '0';
	}
}
