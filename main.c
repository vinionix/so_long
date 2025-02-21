/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:45:09 by vfidelis          #+#    #+#             */
/*   Updated: 2025/02/12 17:23:35 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_matrix	matrix;

	matrix.matrix_map = NULL;
	if (argc != 2)
		ft_error(NULL);
	ft_parsing(argv[1], &matrix);
	matrix.mlx = mlx_init();
    matrix.win = mlx_new_window(matrix.mlx, matrix.len_y * 32, matrix.len_x * 32, "so_long");
	ft_load_assets(&matrix);
	ft_render_map(&matrix);
	mlx_key_hook(matrix.win, ft_handle_keypress, &matrix);
	mlx_loop(matrix.mlx);
}
