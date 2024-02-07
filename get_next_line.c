/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:26:05 by jalbiser          #+#    #+#             */
/*   Updated: 2024/02/07 09:49:34 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*save = NULL;
	char		*line;
	int			read_on;

	if ((fd < 0) || (BUFFER_SIZE <= 0) || (read(fd, 0, 0) == -1))
		return (NULL);
	line = NULL;
	search_line(fd, &save, &line, &read_on);
	return (line);
}

void	search_line(int fd, char **save, char **line, int *read_on)
{
	char	*buff;

	*read_on = 1;
	while (*read_on > 0 && !new_line(*save))
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return ;
		*read_on = (int)read(fd, buff, BUFFER_SIZE);
		if ((*save == NULL && *read_on == 0) || (*read_on == -1))
		{
			free(buff);
			return ;
		}
		buff[*read_on] = '\0';
		(*save) = ft_strjoin(*save, buff);
		free(buff);
	}
	if ((*save)[0] == '\0')
	{
		free_save(*save);
		return ;
	}
	ft_get_line(*save, line);
	clear_save(save);
}

void	clear_save(char **save)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while ((*save)[i] && (*save)[i] != '\n')
		i++;
	if ((*save)[i] == '\n')
		i++;
	tmp = malloc(sizeof(char) * ((ft_strlen(*save) - i) + 1));
	if (!tmp)
		return ;
	j = 0;
	while ((*save)[i] != '\0')
		tmp[j++] = (*save)[i++];
	tmp[j] = '\0';
	free(*save);
	(*save) = ft_strdup(tmp);
	free(tmp);
}

void	ft_get_line(char *save, char **line)
{
	int		i;
	char	*str;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return ;
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		str[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	(*line) = ft_strjoin(*line, str);
	free(str);
}
