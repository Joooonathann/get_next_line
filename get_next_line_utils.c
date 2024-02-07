/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:26:15 by jalbiser          #+#    #+#             */
/*   Updated: 2024/02/07 09:46:01 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	char	*current_ptr;
	char	*previous;

	if (!s1 && !s2)
		return (NULL);
	else if (!s2)
		return (ft_strdup(s1));
	else if (!s1)
		return (ft_strdup(s2));
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	current_ptr = ptr;
	previous = s1;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	free_save(previous);
	return (current_ptr);
}

void	free_save(char *save)
{
	if (save)
	{
		free(save);
		save = NULL;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	new_line(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup(char	*tmp)
{
	char	*result;
	int		i;

	result = malloc(sizeof(char) * (ft_strlen(tmp) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (tmp[i])
	{
		result[i] = tmp[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
