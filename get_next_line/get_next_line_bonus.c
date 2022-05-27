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
	//verify if the file descriptor and the buffer size are valid
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = 0;
	digit = 1;
	//loop only stops when it finds a "break"
	while (1)  
	{
		//if there is nothing inside file we use read()
		//digit - receives a positive number if it is able to read something
		//file - receives x bytes, x being the size of buffer_size
		if (!file[fd][0])
			digit = read(fd, file[fd], BUFFER_SIZE);
		//if read() is able to read something we add what is inside of our file to our line
		//if there is a \n in the middle of the file, we dont add anything after \n to the line
		//example: "1234\n5678" on this string we would only add the first half to our line
		if (digit > 0)
			line = ft_strjoin(line, file[fd]);
		//if there is a \n on the string OR if digit is 0 or less(read() was not able to read anything) the loop ends
		//since the string had a \n we will not empty our file tottaly so when we call gnl again we cant use read
		//the solution to this is to put everything we used as null characters at the end of the string
		//example of ft_update_file: "1234\n5678" on this string the function would update it to this 5678\0\0\0\0\0
		if (ft_update_file(file[fd]) || digit < 1)
			break ;
	}
	return (line);
}
