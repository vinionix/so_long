/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 05:49:12 by vfidelis          #+#    #+#             */
/*   Updated: 2025/02/21 08:30:11 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_render_map(t_matrix *matrix)
{
	int x;
	int y;

	y = 0;
	while (y < (int)matrix->len_y)
	{
		x = 0;
		while (x < (int)matrix->len_x)
		{
			mlx_put_image_to_window(matrix->mlx, matrix->win, matrix->assets.floor, x * 16, y * 16);
			if (matrix->matrix_map[y][x] == '1')
				mlx_put_image_to_window(matrix->mlx, matrix->win, matrix->assets.wall, x * 16, y * 16);
			else if (matrix->matrix_map[y][x] == 'P')
				mlx_put_image_to_window(matrix->mlx, matrix->win, matrix->assets.player, x * 16, y * 16);
			else if (matrix->matrix_map[y][x] == 'C')
				mlx_put_image_to_window(matrix->mlx, matrix->win, matrix->assets.collectible, x * 16, y * 16);
			else if (matrix->matrix_map[y][x] == 'E')
				mlx_put_image_to_window(matrix->mlx, matrix->win, matrix->assets.exit, x * 16, y * 16);
			x++;
		}
		y++;
	}
}