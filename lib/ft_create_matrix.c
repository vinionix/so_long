/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:51:55 by vfidelis          #+#    #+#             */
/*   Updated: 2025/02/25 17:33:56 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_create_matrix(t_matrix *ft_matrix, char **matrix, int options)
{
	t_map	*map;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	map = ft_matrix->ft_map;
	if (options == 1)
	{
		ft_matrix->matrix_map = malloc(sizeof(char *) * ft_lstsize(map));
		while (map->next)
		{
			ft_matrix->matrix_map[i] = map->str;
			i++;
			map = map->next;
		}
		ft_matrix->matrix_map[i] = NULL;
	}
	else
	{
		while (map->next != NULL)
		{
			matrix[i] = malloc(sizeof(char) * (ft_strlen(map->str) + 1));
			while (map->str[j])
			{
				matrix[i][j] = map->str[j];
				j++;
			}
			j = 0;
			i++;
			map = map->next;
		}
	}
	i = 0;
}
