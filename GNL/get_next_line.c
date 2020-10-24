/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 16:26:23 by jkeum             #+#    #+#             */
/*   Updated: 2020/10/24 16:48:43 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		is_newline(char *save)
{
	int	i;

	if (!save)
		return (0);
	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_line(char *save)
{
	int		i;
	int		dest_len;
	char	*dest;

	dest_len = 0;
	while (save[dest_len] && save[dest_len] != '\n')
		dest_len++;
	if (!(dest = (char *)malloc(dest_len + 1)))
		return (NULL);
	i = -1;
	while (++i < dest_len)
		dest[i] = save[i];
	dest[i] = '\0';
	return (dest);
}

char	*get_save(char *save)
{
	int		i;
	int		j;
	int		save_len;
	char	*dest;

	save_len = ft_strlen(save);
	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	i++;
	if (!(dest = (char *)malloc(save_len - i + 1)))
		return (NULL);
	j = 0;
	while (save[i])
		dest[j++] = save[i++];
	dest[j] = '\0';
	free(save);
	return (dest);
}

int		get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*save;
	int			read_len;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buff = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	read_len = 1;
	while (!is_newline(save) && read_len != 0)
	{
		if ((read_len = read(fd, buff, BUFFER_SIZE)) < 0)
			return (-1);
		buff[read_len] = '\0';
		if (!(save = ft_strjoin_gnl(save, buff)))
			return (-1);
	}
	free(buff);
	*line = get_line(save);
	save = get_save(save);
	if (!save)
		return (0);
	return (1);
}
