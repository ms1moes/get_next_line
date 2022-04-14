/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:35:57 by msimoes-          #+#    #+#             */
/*   Updated: 2022/03/31 18:00:41 by msimoes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	file[OPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			digit;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = 0;
	digit = 1;
	while (1)
	{
		if (!file[fd][0])
			digit = read(fd, file[fd], BUFFER_SIZE);
		if (digit > 0)
			line = ft_strjoin(line, file[fd]);
		if (ft_update_file(file[fd]) || digit < 1)
			break ;
	}
	return (line);
}
