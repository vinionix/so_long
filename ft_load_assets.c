/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_assets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 05:55:57 by vfidelis          #+#    #+#             */
/*   Updated: 2025/02/21 08:08:17 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_load_assets(t_matrix *matrix)
{
	int w;
	int h;

	matrix->assets.player = mlx_xpm_file_to_image(matrix->mlx, "player.xpm", &w, &h);
	if (!matrix->assets.player) printf("Erro ao carregar player.xpm\n");

	matrix->assets.wall = mlx_xpm_file_to_image(matrix->mlx, "wall.xpm", &w, &h);
	if (!matrix->assets.wall) printf("Erro ao carregar wall.xpm\n");

	matrix->assets.floor = mlx_xpm_file_to_image(matrix->mlx, "floor.xpm", &w, &h);
	if (!matrix->assets.floor) printf("Erro ao carregar floor.xpm\n");

	matrix->assets.collectible = mlx_xpm_file_to_image(matrix->mlx, "collectible.xpm", &w, &h);
	if (!matrix->assets.collectible) printf("Erro ao carregar collectible.xpm\n");

	matrix->assets.exit = mlx_xpm_file_to_image(matrix->mlx, "exit.xpm", &w, &h);
	if (!matrix->assets.exit) printf("Erro ao carregar exit.xpm\n");

	// Se algum asset falhou, encerra o programa
	if (!matrix->assets.player || !matrix->assets.wall || !matrix->assets.floor ||
		!matrix->assets.collectible || !matrix->assets.exit)
	{
		perror("Erro ao carregar os assets");
		exit(1);
	}
}