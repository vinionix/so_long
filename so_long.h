/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:58:38 by vfidelis          #+#    #+#             */
/*   Updated: 2025/02/13 00:33:55 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include "gnl/get_next_line.h"
# include "lib/libft.h"

typedef struct j_list
{
	char			*str;
	struct j_list	*next;
}	t_map;

typedef struct h_list
{
	char			**matriz_map;
	int				len_x;
	int				len_y;
	t_map	*ft_map;
}	t_matrix;


t_map				*ft_lstnew(char *content);

void				ft_lstadd_back(t_map **lst, t_map *new);

void				ft_free_lst(t_map **a);

#endif