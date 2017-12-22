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
	char	buf1[BUF_SIZE + 1];
	int		len;

	len = 0;
	while ((read(fd, buf1, BUF_SIZE)) != 0)
		len++;
	close(fd);
	return (len);
}

char	*gnl_cat(char *s1, const char *s2)
{
	size_t x;

	x = ft_strlen(s1);
	while (*s2 != '\0')
		s1[x++] = *s2++;
	s1[x++] = '\0';
	return (s1);
}

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

//	if (fd == list->fd)
//		ret = list->countch;
	if (list != NULL)
	{
		s2 = list->content;
		x = 0;
		while (*s2 && *s2 != '\n')
			buff[x++] = *s2++;
		buff[x++] = '\0';
		//buff = ft_strcat(buff, list->content);
		if (s2[x] == '\n')
		{
			list->content = s2 + 1;
			*line = buff;
			return (1);
		}
		ret = x + 1;
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
				ft_bzero(buf1 + BUF_SIZE, 2);
				buff[ret] = '\0';
				if (list == NULL)
				{
					list = ft_lstnew((void *)(buf1 + j), ft_strlen(buf1 + j));
					list->content_size = fd;
				}
				else if (list->content_size != fd, list->next == NULL)
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

//		j = 0;
//		while (buf1[j])
//		{
//
////			buff[ret] = buf1[j];
//			if (buf1[j] == '\n')
//			{
////				list->countch = ret -3;
////				list->fd = fd;
////				list = list->next;
//				return (1);
//			}
//			ret++;
//			j++;
//		}

	}

	return (0);
}