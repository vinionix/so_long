/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:46:20 by vfidelis          #+#    #+#             */
/*   Updated: 2025/02/26 22:37:30 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	aux_verify_floodf(char **matrix, t_matrix *ft_matrix)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (matrix[x] != NULL)
	{
		while (matrix[x][y] != '\0')
		{
			if (matrix[x][y] == 'C')
			{
				ft_free(matrix);
				free(ft_matrix->matrix_map);
				ft_free_lst(ft_matrix->ft_map);
				ft_error();
			}
			y++;
		}
		y = 0;
		x++;
	}
	ft_free(matrix);
}
