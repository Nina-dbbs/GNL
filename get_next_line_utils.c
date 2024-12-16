/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:10:23 by ndabbous          #+#    #+#             */
/*   Updated: 2024/12/16 14:39:15 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t element, size_t size)
{
	size_t	i;
	size_t	bytes;
	char	*str;

	i = 0;
	bytes = element * size;
	if (size && ((bytes / size) != element))
		return (NULL);
	str = (char *)malloc(element * size);
	if (!str)
		return (NULL);
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	if (c == '\0' && s[i] == '\0')
		return (&s[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*copy;

	if (!s1)
		s1 = ft_calloc(1, 1);
	if (!s1 || !s2)
		return (NULL);
	copy = ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!copy)
		return (NULL);
	i = -1;
	while (s1 && s1[++i])
		copy[i] = s1[i];
	j = 0;
	while (s2 && s2[j])
		copy[i++] = s2[j++];
	copy[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (copy);
}
