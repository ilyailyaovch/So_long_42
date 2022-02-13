/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:36:43 by rtracee           #+#    #+#             */
/*   Updated: 2022/02/13 11:19:50 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_key_a(t_data *data, int j, int i)
{
	if (ft_is_1(data, i, j - 1) == 0 && ft_is_e(data, i, j - 1) == 0)
		ft_go_left(data, i, j);
	else if (ft_is_1(data, i, j - 1) == 0 && ft_is_e(data, i, j - 1) == 1)
	{
		data->step = ft_step(data);
		ft_back(data);
		ft_win(data);
		data->done++;
	}
}

void	ft_key_d(t_data *data, int j, int i)
{
	if (ft_is_1(data, i, j + 1) == 0 && ft_is_e(data, i, j + 1) == 0)
		ft_go_right(data, i, j);
	else if (ft_is_1(data, i, j + 1) == 0 && ft_is_e(data, i, j + 1) == 1)
	{
		data->step = ft_step(data);
		ft_back(data);
		ft_win(data);
		data->done++;
	}
}

void	ft_key_w(t_data *data, int j, int i)
{
	if (ft_is_1(data, i - 1, j) == 0 && ft_is_e(data, i - 1, j) == 0)
		ft_go_up(data, i, j);
	else if (ft_is_1(data, i - 1, j) == 0 && ft_is_e(data, i - 1, j) == 1)
	{
		data->step = ft_step(data);
		ft_back(data);
		ft_win(data);
		data->done++;
	}
}

void	ft_key_s(t_data *data, int j, int i)
{
	if (ft_is_1(data, i + 1, j) == 0 && ft_is_e(data, i + 1, j) == 0)
		ft_go_down(data, i, j);
	else if (ft_is_1(data, i + 1, j) == 0 && ft_is_e(data, i + 1, j) == 1)
	{
		data->step = ft_step(data);
		ft_back(data);
		ft_win(data);
		data->done++;
	}
}

int	ft_key(int keycode, t_data *data)
{
	int	i;
	int	j;

	j = data->player_x;
	i = data->player_y;
	if (keycode == KEY_ESC)
		exit (0);
	if (keycode == KEY_A && data->done == 0)
		ft_key_a(data, j, i);
	if (keycode == KEY_D && data->done == 0)
		ft_key_d(data, j, i);
	if (keycode == KEY_W && data->done == 0)
		ft_key_w(data, j, i);
	if (keycode == KEY_S && data->done == 0)
		ft_key_s(data, j, i);
	return (0);
}
