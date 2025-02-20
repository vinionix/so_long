/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:58:38 by vfidelis          #+#    #+#             */
/*   Updated: 2025/02/13 08:26:16 by vfidelis         ###   ########.fr       */
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
	struct j_list	*prev;
	char			*str;
	struct j_list	*next;
}	t_map;

typedef struct h_list
{
	char				**matrix_map;
	size_t				len_x;
	size_t				len_y;
	size_t				c;
	t_map				*ft_map;
}	t_matrix;

t_map	*ft_lstnew(char *content);

size_t	ft_lstsize(t_map *lst);

size_t	ft_strlen_newline(char *str);

size_t	ft_len_last(t_map *ft_map);

size_t	ft_last_lst(t_matrix *ft_matrix);

size_t	ft_strrchr(const char *str, int c);

void	ft_lstadd_back(t_map **lst, t_map *new);

void	ft_free_lst(t_map *a);

void	ft_parsing(char *argv, t_matrix *matrix);

void	ft_error(t_matrix *ft_matrix);

void	ft_create_matrix(t_matrix *ft_matrix, char **matrix, int opitions);

#endif
