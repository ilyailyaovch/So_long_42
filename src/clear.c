/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 09:57:55 by rtracee           #+#    #+#             */
/*   Updated: 2022/02/13 10:52:40 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_clear_mas(t_data data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= data.height)
	{
		free(data.map[i]);
		i++;
	}
	free(data.map);
}

void	ft_clear_mas_val(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= data->height)
	{
		while (j <= data->width)
		{
			free(&data->map[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_clear(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}
