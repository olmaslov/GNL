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

int		line_lenght(char *line)
{

}

int		get_next_line(const int fd, char **line)
{
	char buf[BUF_SIZE];
	int i;
	long long int j;
	char *s;

	s = line;
	i = 0;
	while((read(fd, buf, BUF_SIZE)) > 0)
	{
		j = 0;
		while (j < BUF_SIZE && buf[j] != '\n')
		{
			*s = buf[j];
			s++;
			j++;
		}
	}
	return (1);
}