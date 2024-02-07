/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:26:10 by jalbiser          #+#    #+#             */
/*   Updated: 2024/02/07 09:48:51 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
void	search_line(int fd, char **save, char **line, int *read_on);
void	clear_save(char **save);
char	*ft_strdup(char	*tmp);
void	ft_get_line(char *save, char **line);
char	*ft_strjoin(char *s1, char *s2);
void	free_save(char *save);
int		ft_strlen(char *str);
int		new_line(char *str);

#endif
