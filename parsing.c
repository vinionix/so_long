/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+        +:+      */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+      +#+         */
/*                                                +#+#+#+#+#+  	+#+           */
/*   Created: 2025/02/12 15:19:27 by vfidelis          #+#    #+#             */
/*   Updated: 2025/02/13 09:02:22 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_flood_fill(char **grid, int l, int c, t_matrix *ft_matrix)
{
	if (l < 0 || c < 0 || l >= (int)ft_matrix->len_x
		|| c >= (int)ft_matrix->len_y)
		return ;
	if (grid[l][c] != '0' && grid[l][c] != 'C' && grid[l][c] != 'P')
		return ;
	grid[l][c] = 'F';
	ft_flood_fill(grid, l - 1, c, ft_matrix);
	ft_flood_fill(grid, l + 1, c, ft_matrix);
	ft_flood_fill(grid, l, c - 1, ft_matrix);
	ft_flood_fill(grid, l, c + 1, ft_matrix);
}

void static	ft_verify_floodf(t_matrix *ft_matrix)
{
	char	**matrix;
	int		l;
	int		c;

	l = 0;
	c = 0;
	matrix = malloc(sizeof(char *) * ft_lstsize(ft_matrix->ft_map));
	ft_create_matrix(ft_matrix, matrix, 2);
	while (matrix[l] != NULL)
	{
		while (matrix[l][c] != 'P' && matrix[l][c] != '\0')
			c++;
		if (matrix[l][c] == 'P')
			break ;
		c = 0;
		l++;
	}
	ft_flood_fill(matrix, l, c, ft_matrix);
	aux_verify_floodf(matrix, ft_matrix);
}

static void	ft_checker_pec01(t_matrix *ft_matrix, int i)
{
	char	chr_valid[6];
	t_map	*map;
	int		p;
	int		e;

	p = 0;
	e = 0;
	map = ft_matrix->ft_map;
	ft_strlcpy(chr_valid, "PEC01", 6);
	while (map->next)
	{
		while (map->str[i] && map->str[i + 1] != '\n' && map->str != NULL)
		{
			if (ft_strrchr(chr_valid, map->str[i]) != 0)
				ft_error(ft_matrix);
			if (map->str[i] == 'E')
				e++;
			if (map->str[i] == 'P')
				p++;
			if (map->str[i] == 'C')
				ft_matrix->c++;
			i++;
		}
		i = 0;
		map = map->next;
	}
	if (p != 1 || e != 1)
		ft_error(ft_matrix);
	ft_create_matrix(ft_matrix, NULL, 1);
	ft_verify_floodf(ft_matrix);
}

static void	ft_checker_wall(t_matrix *ft_matrix)
{
	t_map	*receiver;
	size_t	i;

	if (ft_matrix->len_x == ft_matrix->len_y)
		ft_error(ft_matrix);
	receiver = ft_matrix->ft_map;
	while (receiver->next != NULL)
	{
		i = 0;
		if (receiver->prev == NULL || receiver->next == NULL)
		{
			while (receiver->str[i] == '1')
				i++;
			if (i != ft_matrix->len_y)
				ft_error(ft_matrix);
		}
		else if (receiver->str != NULL)
		{
			i = ft_matrix->len_y - 1;
			if (receiver->str[0] != '1' || receiver->str[i] != '1')
				ft_error(ft_matrix);
		}
		receiver = receiver->next;
	}
	i = 0;
	ft_checker_pec01(ft_matrix, i);
}

void	ft_parsing(char *argv, t_matrix *ft_matrix)
{
	t_map	*receiver;
	int		fd;

	fd = open(argv, O_RDONLY);
	ft_matrix->ft_map = ft_lstnew(get_next_line(fd));
	if (ft_matrix->ft_map->str == NULL)
		ft_error(ft_matrix);
	receiver = ft_matrix->ft_map;
	while (receiver->str != NULL)
	{
		ft_lstadd_back(&ft_matrix->ft_map, ft_lstnew(get_next_line(fd)));
		receiver = receiver->next;
	}
	receiver = ft_matrix->ft_map;
	ft_matrix->len_y = ft_last_lst(ft_matrix);
	while (receiver->str != NULL)
	{
		if (ft_strlen_newline(receiver->str) != ft_matrix->len_y)
			ft_error(ft_matrix);
		receiver = receiver->next;
	}
	close(fd);
	ft_matrix->len_x = ft_lstsize(ft_matrix->ft_map) - 1;
	ft_checker_wall(ft_matrix);
}
