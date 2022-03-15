/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherki <mcherki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:29:35 by mcherki           #+#    #+#             */
/*   Updated: 2022/03/15 17:24:18 by mcherki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buff[2];
	char	*line;
	int		n;
	void	*d_ptr;

	if (fd < 0)
		return (NULL);
	buff[0] = 0;
	buff[1] = 0;
	line = ft_strdup("");
	n = 1;
	while (n > 0)
	{
		n = read(fd, buff, 1);
		if (n <= 0)
			continue ;
		d_ptr = line;
		line = ft_strjoin(line, buff);
		free(d_ptr);
		if (buff[0] == '\n')
			return (line);
	}
	if (line && !*line)
		return (free(line), NULL);
	return (line);
}
