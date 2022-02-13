/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:48:23 by rtracee           #+#    #+#             */
/*   Updated: 2022/02/13 11:09:00 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_is_1(t_data *data, int i, int j)
{
	if (data->map[i][j] != '1')
		return (0);
	else
		return (1);
}

int	ft_is_e(t_data *data, int i, int j)
{
	if (data->map[i][j] != 'E' && data->is_col >= 0)
		return (0);
	else if (data->map[i][j] == 'E' && data->is_col == 0)
		return (1);
	else
		return (-1);
}

int	ft_step(t_data *data)
{
	data->step++;
	data->step_str = ft_itoa(data->step);
	ft_putstr("step = ");
	ft_putnbr(data->step);
	ft_putstr("\n");
	free(data->step_str);
	return (data->step);
}

void	ft_win(t_data *data)
{
	int	i;
	int	j;

	i = data->width / 2 * 50;
	j = data->height / 2 * 50;
	mlx_put_image_to_window(data->mlx, data->window, data->player_r, i, j);
	mlx_string_put(data->mlx, data->window, i, j + 70, 0xFF0000, "YOU WIN");
}
