/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:19:27 by vfidelis          #+#    #+#             */
/*   Updated: 2025/02/13 00:32:51 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_lst(t_map **a)
{
	t_map	*temp;

	temp = NULL;
	while (*a)
	{
		temp = (*a)->next;
		free((*a)->str);
		free(*a);
		(*a) = temp;
	}
}

void	ft_parsing(char *argv, t_matrix *ft_matrix)
{
	
	t_map	*receiver;
	int		fd;
	size_t	len;

	fd = open(argv, O_RDONLY);
	ft_matrix->ft_map = ft_lstnew(get_next_line(fd));
	len = ft_strlen(ft_matrix->ft_map->str);
	receiver = ft_matrix->ft_map;
	while (receiver->str != NULL)
	{
		ft_lstadd_back(&ft_matrix->ft_map, ft_lstnew(get_next_line(fd)));
		receiver = receiver->next;
		if (ft_strlen(receiver->str) != len)
		{
			ft_free_lst(&ft_matrix->ft_map);
			perror("ola");
			exit(1);
		}
	}
	
}