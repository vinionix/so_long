/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_keypress.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 06:11:16 by vfidelis          #+#    #+#             */
/*   Updated: 2025/02/21 06:57:14 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_handle_keypress(int keycode, t_matrix *matrix)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(matrix->mlx, matrix->win);
		exit(0);
	}
	else if (keycode == W_KEY)
		ft_move_player(matrix, 0, -1);
	else if (keycode == S_KEY)
		ft_move_player(matrix, 0, 1);
	else if (keycode == A_KEY)
		ft_move_player(matrix, -1, 0);
	else if (keycode == D_KEY)
		ft_move_player(matrix, 1, 0);
	mlx_clear_window(matrix->mlx, matrix->win);
	ft_render_map(matrix);
	return (0);
}