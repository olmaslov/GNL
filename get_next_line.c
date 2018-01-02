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

t_file	*listfilenew(void const *content, size_t content_size, int fd, t_file *list)
{
	t_file *new;

	if (!(new = (t_file *)malloc(sizeof(*new))))
		return (NULL);
	if (!(new->content = malloc(content_size)))
	{
		free(new);
		return (NULL);
	}
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
		new->fd = fd;
		new->next = list;
		return (new);
	}
	new->fd = fd;
	new->content_size = content_size;
	ft_memcpy(new->content, content, content_size);
	new->next = list;
	return (new);
}

t_file	*searchfd(int fd, t_file *list)
{
	t_file	*listf;
	t_file	*temp;

	listf = list;
	temp = list;
	while (listf->fd != fd)
	{
		listf = listf->next;
		if (listf == temp)
			break;
	}
	return (listf);
}

int		get_next_line(const int fd, char **line)
{
	char	buf1[BUFF_SIZE + 1];
	char	*buff;
	char	*s2;
	int		ret;
	int		j;
	static 	t_file	*list;
	int		s;
	size_t x;

	ret = 0;
	buff = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	if (list != NULL && list->fd != fd)
	{
		list = searchfd(fd, list);
	}
	if (list != NULL && list->fd == fd)
	{
//		while (list->fd != fd && list->next != NULL)

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
	while ((s = read(fd, buf1, BUFF_SIZE)) != 0)
	{
		j = 0;
		if (s == -1)
			return (-1);
		while (j < BUFF_SIZE)
		{
			buff[ret] = buf1[j];
			if (buf1[j] == '\n' || buf1[j] == '\0')
			{
				if (buf1[j] == EOF)
					return -1;
				j++;
				buf1[BUFF_SIZE] = '\0';
				buff[ret] = '\0';
				if (list == NULL)
				{
					list = listfilenew((void *)(buf1 + j), ft_strlen(buf1 + j), fd, NULL);
					list->next = list;
				}
				else if (list->fd != fd)
				{
					list->next = listfilenew((void *)(buf1 + j), ft_strlen(buf1 + j), fd, list);
					list = list->next;

				}
				else
				{
					list->content = ft_strdup(buf1 + j);
					list->fd = fd;
				}
				*line = buff;
				return (1);
			}
			buff = ft_strjoin(ft_strnew(BUFF_SIZE + 1), buff);
			ret++;
			j++;
		}
	}
	if (s == 0 && buff[0] != '\0')
		*line = buff;
	return (0);
}