/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:31:36 by msimoes-          #+#    #+#             */
/*   Updated: 2022/03/31 17:23:25 by msimoes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

//since we only want to do anything until we find either the end of the string or a new line
//we return if we find a \n or a \0
size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

//its a normal ft_strjoin but it frees the previous string if it exists and also stops copying if it finds a \n
char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = -1;
	ptr = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return (NULL);
	while (s1 && s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[++j])
	{
		ptr[i++] = s2[j];
		if (s2[j] == '\n')
			break ;
	}
	ptr[i] = '\0';
	if (s1)
		free(s1);
	return (ptr);
}

//this function is used to update our buffer for us to be able to call gnl function multiple times
int	ft_update_file(char *buffer)
{
	int		i;
	int		j;
	int		is_nl;

	i = -1;
	is_nl = 0;
	j = 0;
	while (buffer[++i])
	{
		if (is_nl)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			is_nl = 1;
		buffer[i] = 0;
	}
	return (is_nl);
}
