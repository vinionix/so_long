/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:34:55 by vfidelis          #+#    #+#             */
/*   Updated: 2024/11/05 17:42:12 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	if (s[0] == '\0')
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_realloc(char **str1, char *str2)
{
	char	*new_str;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(*str1);
	len2 = ft_strlen(str2);
	new_str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!new_str)
		return ;
	ft_memcpy(new_str, *str1, len1);
	ft_memcpy(new_str + len1, str2, len2);
	new_str[len1 + len2] = '\0';
	free(*str1);
	*str1 = new_str;
}

void	new_pos(char **buffer, char *pos)
{
	char	*temp;
	size_t	len;

	len = ft_strlen(pos);
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (!temp)
		return ;
	ft_memcpy(temp, pos, len);
	temp[len] = '\0';
	free(*buffer);
	*buffer = temp;
}
