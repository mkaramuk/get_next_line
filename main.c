/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devman <devman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 10:04:35 by devman            #+#    #+#             */
/*   Updated: 2022/01/23 15:08:20 by devman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	size_t	i;

	if (argc < 2)
	{
		printf("Please enter a file\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("'%s' file couldn't open.\n", argv[1]);
		return (1);
	}
	for (i = 0, line = get_next_line(fd);
		line != NULL;
		i++, line = get_next_line(fd))
	{
		printf("\nline: %d - {%s} \n", i, line);
		free(line);
	}
	printf("\nThat's all folks!\n\n");
#ifdef __APPLE__
	printf("Run 'leaks' for leak detection: %d " \
			"(leaks return code)\n", system("leaks gnl"));
#endif
#ifdef __linux__
	printf("I don't know what should I do for leaks checking :/\nBut I am sure there ain't any leaks around here [:-)\n\n");
	printf("And here is your gift for using Linux:\n");
	printf("                 ----------------------\n" \
"         ___     |  Hello, World!     |\n" \
"       =======   |  Hello Linux User! |\n" \
"        (o>o) -------------------------\n" \
"        /[1]/\n" \
"         [1]\n" \
"        /   \\\n");
#endif
#ifdef _WIN32
	printf("Do you using the dammit OS!? I am getting out from here!\n");
	return (1);
#endif
	return (0);
}