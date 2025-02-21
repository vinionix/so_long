/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 06:42:42 by vfidelis          #+#    #+#             */
/*   Updated: 2025/02/21 08:06:16 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_move_player(t_matrix *matrix, int dx, int dy)
{
	int x, y;

	// Encontrar a posição atual do jogador ('P')
	y = 0;
	while (y < (int)matrix->len_x)
	{
		x = 0;
		while (x < (int)matrix->len_y)
		{
			if (matrix->matrix_map[y][x] == 'P')  // Encontramos o jogador
			{
				int new_x = x + dx;
				int new_y = y + dy;

				// Verifica se a nova posição está dentro dos limites
				if (new_x < 0 || new_x >= (int)matrix->len_y || new_y < 0 || new_y >= (int)matrix->len_x)
					return;

				// Verifica se o jogador pode andar (não pode atravessar paredes)
				if (matrix->matrix_map[new_y][new_x] == '1')
					return;

				// Se houver um coletável na nova posição, conta
				if (matrix->matrix_map[new_y][new_x] == 'C')
					matrix->c--; // Reduz o número de coletáveis restantes

				// Move o jogador
				matrix->matrix_map[y][x] = '0';   // Posição antiga vira chão
				matrix->matrix_map[new_y][new_x] = 'P';  // Nova posição recebe o jogador

				// Se o jogador alcançar a saída e tiver coletado todos os itens, ele vence
				if (matrix->matrix_map[new_y][new_x] == 'E' && matrix->c == 0)
				{
					printf("Parabéns! Você venceu!\n");
					exit(0);
				}
				return;
			}
			x++;
		}
		y++;
	}
}
