/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:51:55 by vfidelis          #+#    #+#             */
/*   Updated: 2025/02/18 21:29:52 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_create_matrix(t_matrix *ft_matrix)
{
	t_map	*map;
	size_t	i;

	i = 0;
	map = ft_matrix->ft_map;
	ft_matrix->matrix_map = malloc(sizeof(char *) * ft_lstsize(map));
	while (map->next)
	{
		ft_matrix->matrix_map[i] = map->str;
		i++;
		map = map->next;
	}
	ft_matrix->matrix_map[i] = NULL;
}
