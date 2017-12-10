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
	char *line;

	line = (char *)malloc(10000);
	//line = "/* ************************************************************************** */";
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, line);
	printf("%s\n", line);
	return (0);
}

