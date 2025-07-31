/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmmous <mahmmous@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:51:48 by mahmmous          #+#    #+#             */
/*   Updated: 2025/07/31 11:51:48 by mahmmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *read_to_stash(int fd, char *stash)
{
	char buffer[BUFFER_SIZE + 1];
	int bytes_read;

	while(!stash || !ft_strchr(stash, '\n'))
	{
		if (bytes_read == -1)
			return (NULL);
		if (bytes_read == 0)
			break;
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	return (stash);
}

static char *extract_line(const char *stash)
{
    int line_len;

	line_len = 0;
	if(!stash || !*stash)
		return (NULL);
	while((stash[line_len] && stash[line_len] !='\n'))
		line_len++;
	if(stash[line_len] == '\n')
		line_len++;
	return(ft_substr(stash, 0, line_len));
}
static char *get_remainder(char *stash)
{
	int line_len;
	int remainder_len;
	char *remainder;

	line_len = 0;
	remainder_len 0;
	while(stash[line_len] != '\n' || stash[line_len] != '\0')
	{
		if(!stash[line_len])
		{
			free(stash);
			return (NULL);
			line_len++;
		}
		remainder_len = ft_strlen(stash) - line_len;
		remainder = ft_substr(stash, remainder_len, );
	}
	free(stash);
	return (remainder);
}

char *get_next_line(int fd)
{
    static char *stash;
    char        *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    stash = read_to_stash(fd, stash);

    if (!stash)
        return (NULL);

    line = extract_line(stash);
    stash = get_remainder(stash);

    return (line);
}
