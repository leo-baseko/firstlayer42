/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:55:27 by ldrieske          #+#    #+#             */
/*   Updated: 2023/03/19 19:01:48 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	line_count(char line)
{
	static int count;

	count = 0;
	
}

/*
 * get_next_line
 *
 * Returns the line that was read. If there's nothing/an error, returns NULL
 * 
 * int fd : file descriptor with the sweets lines we want
*/

char	*get_next_line(int fd)
{
	write(1, &fd, 1);
	return (fd);
}
