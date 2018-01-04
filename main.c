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
#include "gnl_in/get_next_line.h"

//int main(int argc, char **argv)
//{
//	int fd;
//	int fd1;
//	int fd2;
//	char *line;
//	int i;
//
//	line =  (char *)malloc(sizeof(char) * 1000);
//	fd = open(argv[1], O_RDONLY);
//	fd1 = open(argv[2], O_RDONLY);
//	fd2 = open(argv[3], O_RDONLY);
//	//get_next_line(-99, ((void *)0));
////	get_next_line(fd, &line);
////	printf("%s\n", line);
//	get_next_line(fd, &line);
//	printf("%s\n", line);
//	get_next_line(fd2, &line);
//	printf("%s\n", line);
//	get_next_line(fd, &line);
//	printf("%s\n", line);
//	get_next_line(fd, &line);
//	printf("%s\n", line);
//	get_next_line(fd, &line);
//	printf("%s\n", line);
////	get_next_line(fd1, &line);
////	printf("%s\n", line);
////	get_next_line(fd2, &line);
////	printf("%s\n", line);
//	get_next_line(fd1, &line);
//	printf("%s\n", line);
////	get_next_line(fd2, &line);
////	printf("%s\n", line);
//
//	return (0);
//}

//
//int				main(void)
//{
//	char		*line;
//	int			fd;
//	int			ret;
//	int			count_lines;
//	char		*filename;
//	int			errors;
//
//	filename = "../gnl3_2.txt";
//	fd = open(filename, O_RDONLY);
//	if (fd > 2)
//	{
//		count_lines = 0;
//		errors = 0;
//		line = NULL;
//		while ((ret = get_next_line(fd, &line)) > 0)
//		{
//			if (count_lines == 0 && strcmp(line, "1234567890abcde") != 0)
//				errors++;
//			if (count_lines == 1 && strcmp(line, "fghijklmnopqrst") != 0)
//				errors++;
//			count_lines++;
//			if (count_lines > 50)
//				break ;
//		}
//		close(fd);
//		if (count_lines != 2)
//			printf("-> must have returned '1' twice instead of %d time(s)\n", count_lines);
//		if (errors > 0)
//			printf("-> must have read \"1234567890abcde\" and \"fghijklmnopqrst\"\n");
//		if (count_lines == 2 && errors == 0)
//			printf("OK\n");
//	}
//	else
//		printf("An error occured while opening file %s\n", filename);
//	return (0);
//}

