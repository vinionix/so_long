/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:25:21 by vfidelis          #+#    #+#             */
/*   Updated: 2025/02/13 05:41:01 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_lstsize(t_map *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

/*int main()
{
    t_list *lststart;
    t_list *lstbody;
    t_list *lstend;
    int count;

    lststart = malloc (sizeof(t_list));
    lstbody = malloc (sizeof(t_list));
    lstend = malloc (sizeof(t_list));

    if (!lststart || !lstend || !lstbody)
        return (1);
    lststart -> next = lstbody;
    lstbody -> next = lstend;
    lstend -> next = NULL;

    count = ft_lstsize(lststart);
    printf("%i", count);
}*/
