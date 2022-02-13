/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:17:56 by rtracee           #+#    #+#             */
/*   Updated: 2022/02/13 11:00:04 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_game(t_data data)
{
	data.mlx = mlx_init();
	data.window = mlx_new_window(data.mlx,
			data.width * 50, (data.height + 1) * 50, "so_long");
	ft_back(&data);
	ft_wall(&data);
	ft_player(&data);
	ft_collect(&data);
	ft_exit(&data);
	mlx_hook (data.window, 2, 0, ft_key, &data);
	mlx_hook (data.window, 17, 0, ft_key_exit, &data);
	mlx_loop(data.mlx);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 2)
	{
		data = (t_data *)malloc(sizeof(t_data));
		if (!data)
		{
			ft_putstr("Error\nMemory allocation error\n");
			return (0);
		}
		if (ft_map_processing(argv[1], data) < 0)
		{
			ft_putstr("Error\nWrong map\n");
			ft_clear_mas(*data);
			free(data);
			return (0);
		}
		ft_game(*data);
		ft_clear_mas_val(data);
		free(data);
	}
	return (0);
}
