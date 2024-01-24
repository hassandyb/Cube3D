/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:43:07 by cgouiame          #+#    #+#             */
/*   Updated: 2024/01/22 18:19:03 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**initialize_map(int *fd, char *av, t_parse *parse)
{
	char	**map;

	parse->flag = 0;
	map = malloc(sizeof(char *) * (getsize(*fd) + 1));
	if (!map)
		ft_error("Error\nmalloc failed\n");
	*fd = open(av, O_RDONLY);
	if (*fd < 0)
		ft_error("Error\nOpen failed\n");
	return (map);
}

char	**read_map(int fd, char *av, t_parse *parse)
{
	char	*line;
	char	**map;
	int		i;

	map = initialize_map(&fd, av, parse);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		if (!is_empty(line) || i > 6)
		{
			if (!is_empty(line) && parse->flag == 1)
				ft_error("Error\nEmpty line in Map\n");
			if (is_empty(line) && parse->flag == 0)
				parse->flag = 1;
			map[i++] = ft_strdup(line);
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	map[i] = NULL;
	parse->mapsize = i;
	return (map);
}

void	ft_check_arg(int ac, char **av)
{
	int	i;
	int	fd;

	if (ac != 2)
		ft_error("Error\nCheck arguments\n");
	i = ft_strlen(av[1]) - 4;
	if (ft_strcmp(&av[1][i], ".cub") != 0)
		ft_error("Error\nCheck file extension\n");
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_error("Error\nOpen failed\n");
	if (close(fd) < 0)
		ft_error("Error\nClose failed\n");
}

void	ft_parse(int ac, char **av, t_parse *parse)
{
	int	fd;

	ft_check_arg(ac, av);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_error("Error\nOpen failed\n");
	ft_parse_cub(fd, parse, av[1]);
	close(fd);
}
