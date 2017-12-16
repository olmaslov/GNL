/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslov <omaslov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 17:05:00 by omaslov           #+#    #+#             */
/*   Updated: 2017/12/08 17:05:00 by omaslov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_bufcnt(int fd)
{
	char	buf1[BUF_SIZE];
	int		len;

	len = 0;
	while ((read(fd, buf1, BUF_SIZE)) != 0)
		len++;
	close(fd);
	return (len);
}

int		get_next_line(const int fd, char **line)
{
	char	buf1[BUF_SIZE];
	char	*buff;
	int		ret;
	int		j;
//	static t_file	*list;


	ret = 0;
	buff = line;
//	if (list == NULL)
//		list = malloc(1);
//	if (fd == list->fd)
//		ret = list->countch;
	while (read(fd, buf1, BUF_SIZE))
	{
		j = 0;
		while (buf1[j] != '\0')
		{
			buff[ret] = buf1[j];
			if (buf1[j] == '\n')
			{
//				list->countch = ret -3;
//				list->fd = fd;
//				list = list->next;
				return (1);
			}
			ret++;
			j++;
		}
	}
	return (0);
}