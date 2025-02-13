/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:19:27 by vfidelis          #+#    #+#             */
/*   Updated: 2025/02/13 09:02:22 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

static void	ft_checker_pec01(t_matrix *ft_matrix)
{
	char	chr_valid[6];

	ft_strlcpy(chr_valid, "PEC01", 6);
	
}

static void	ft_checker_wall(t_matrix *ft_matrix)
{
	t_matrix	*receiver;
	size_t		i;

	if (ft_matrix->len_x == ft_matrix->len_y)
		ft_error(ft_matrix);
	receiver = ft_matrix;
	while (receiver->ft_map->next)
	{
		i = 0;
		if (receiver->ft_map->prev == NULL || receiver->ft_map->next == NULL)
		{
			while (receiver->ft_map->str[i] == '1')
				i++;
			if (i != receiver->len_y)
				ft_error(ft_matrix);
		}
		else if (receiver->ft_map->str != NULL)
		{
			i = receiver->len_y - 1;
			if (receiver->ft_map->str[0] != '1'
				|| receiver->ft_map->str[i] != '1')
				ft_error(ft_matrix);
		}
		receiver->ft_map = receiver->ft_map->next;
	}
}

void	ft_parsing(char *argv, t_matrix *ft_matrix)
{
	t_map	*receiver;
	int		fd;
	int		i;

	i = 0;
	fd = open(argv, O_RDONLY);
	ft_matrix->ft_map = ft_lstnew(get_next_line(fd));
	ft_matrix->len_y = ft_strlen_newline(ft_matrix->ft_map->str);
	receiver = ft_matrix->ft_map;
	while (receiver->str != NULL)
	{
		ft_lstadd_back(&ft_matrix->ft_map, ft_lstnew(get_next_line(fd)));
		if (ft_strlen_newline(receiver->str) != ft_matrix->len_y)
			i++;
		receiver = receiver->next;
	}
	close(fd);
	if (i > 0)
		ft_error(ft_matrix);
	ft_matrix->len_x = ft_lstsize(ft_matrix->ft_map) - 1;
	ft_checker_wall(ft_matrix);
	ft_checker_pec01(ft_matrix);
}
