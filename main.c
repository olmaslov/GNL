/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslov <omaslov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 17:02:00 by omaslov           #+#    #+#             */
/*   Updated: 2017/12/08 17:02:00 by omaslov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
	int fd;
	int fd1;
	int fd2;
	char *line;
	int i;

	line = (char *)malloc(10000);
	fd = open(argv[1], O_RDONLY);
	//fd1 = open(argv[2], O_RDONLY);
	//fd2 = open(argv[3], O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);
	}
//	while (get_next_line(fd1, &line))
//	{
//		printf("%s\n", line);
//	}
//	while (get_next_line(fd2, &line))
//	{
//		printf("%s\n", line);
//	}
	return (0);
}
