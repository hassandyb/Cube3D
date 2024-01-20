/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:43:07 by cgouiame          #+#    #+#             */
/*   Updated: 2024/01/19 18:28:33 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**read_map(int fd, char *av, t_parse *parse)
{
	char	*line;
	char	**map;
	int		i;

	parse->flag = 0;
	map = malloc(sizeof(char *) * (getsize(fd) + 1));
	if (!map)
		ft_error("Error: malloc failed\n");
	fd = open(av, O_RDONLY);
	if (fd < 0)
		ft_error("Error: Open failed\n");
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		if (!is_empty(line) || i > 6)
		{
			if (!is_empty(line) && parse->flag == 1)
				ft_error("Error: empty line in Map\n");
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

int	parsemycolor(char *str, t_parse *parse, int flag)
{
	int		i;
	int		cn[3];
	char	**tab;
	int		flag2;

	flag2 = 0;
	i = -1;
	while (str[++i])
		if (str[i] == ',')
			flag2++;
	if (flag2 != 2)
		return (-1);
	tab = ft_split(str, ',');
	i = 0;
	while (tab[i])
		i++;
	if (i != 3)
		return (ft_free_mem(tab), -1);
	i = 0;
	while (tab[i])
	{
		cn[i] = my_atoi(tab[i]);
		if (cn[i] < 0 || cn[i] > 255)
			return (ft_free_mem(tab), -1);
		i++;
	}
	if (flag == 0)
		parse->f = cn[0] << 16 | cn[1] << 8 | cn[2];
	else if (flag == 1)
		parse->c = cn[0] << 16 | cn[1] << 8 | cn[2];
	ft_free_mem(tab);
	return (1);
}

void	ft_check_arg(int ac, char **av)
{
	int	i;
	int	fd;

	if (ac != 2)
		ft_error("Error: Check arguments\n");
	i = ft_strlen(av[1]) - 4;
	if (ft_strcmp(&av[1][i], ".cub") != 0)
		ft_error("Error: Check file extension\n");
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_error("Error: Open failed\n");
	if (close(fd) < 0)
		ft_error("Error: Close failed\n");
}

void	ft_parse(int ac, char **av, t_parse *parse)
{
	int	fd;

	ft_check_arg(ac, av);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_error("Error: Open failed\n");
	ft_parse_cub(fd, parse, av[1]);
	close(fd);
}
