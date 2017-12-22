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

int		get_next_line(const int fd, char **line)
{
	char	buf1[BUF_SIZE + 1];
	char	*buff;
	char	*s2;
	int		ret;
	int		j;
	static 	t_list	*list;
	size_t x;




	ret = 0;
	buff = (char *)malloc(sizeof(char) * 1000);
	if (list != NULL)
	{
		s2 = list->content;
		x = 0;
		while (*s2 && *s2 != '\n')
			buff[x++] = *s2++;
		if (*s2 == '\n')
		{
			list->content = s2 + 1;
			*line = buff;
			return (1);
		}
		ret = x;
	}
	while (read(fd, buf1, BUF_SIZE))
	{
		j = 0;
		while (j < BUF_SIZE)
		{
			buff[ret] = buf1[j];
			if (buf1[j] == '\n')
			{
				j++;
				buf1[BUF_SIZE] = '\0';
				buff[ret] = '\0';
				if (list == NULL)
				{
					list = ft_lstnew((void *)(buf1 + j), ft_strlen(buf1 + j));
					list->content = buf1 + j;
					list->content_size = fd;
				}
				else if (list->content_size |= (size_t)fd, list->next == NULL)
				{
					list->next = ft_lstnew((void *)(buf1 + j), ft_strlen(buf1 + j));
					list = list->next;
					list->content_size = fd;
				}
				else
				{
					list->content = (buf1 + j);
					list->content_size = fd;
				}
				*line = buff;
				return (1);
			}
			ret++;
			j++;
		}
	}

	return (0);
}