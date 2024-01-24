/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:19:06 by cgouiame          #+#    #+#             */
/*   Updated: 2024/01/22 18:18:28 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsecolor(t_parse *parse, int k)
{
	if (parse->map[k][0] == 'F')
	{
		parse->map[k] = ft_erase(parse->map[k]);
		if (parsemycolor(parse->map[k], parse, 0) == -1)
			ft_error("Error\nin floor\n");
	}
	else if (parse->map[k][0] == 'C')
	{
		parse->map[k] = ft_erase(parse->map[k]);
		if (parsemycolor(parse->map[k], parse, 1) == -1)
			ft_error("Error\nin ceiling\n");
	}
}

int	get_longest_line(char **map, int *i)
{
	int	len;

	len = 0;
	*i = -1;
	while (map[++*i])
		if (*i > 5)
			if (len < ft_strlen(map[*i]))
				len = ft_strlen(map[*i]);
	return (len);
}

void	check_var(t_parse *parse)
{
	if (parse->no == NULL || parse->so == NULL || parse->we == NULL
		|| parse->ea == NULL || parse->f == -1 || parse->c == -1)
		ft_error("Error\nin texture\n");
}

void	ft_parse_cub(int fd, t_parse *parse, char *av)
{
	int		k;

	parse->map = read_map(fd, av, parse);
	if (parse->mapsize < 6)
		ft_error("Error\nMap is emppty\n");
	k = -1;
	while (++k < 6)
	{
		parse->map[k] = skip_space(parse->map[k]);
		if (parse->map[k][0] == 'F' || parse->map[k][0] == 'C')
			parsecolor(parse, k);
		else if (parse->map[k][0] == 'N' || parse->map[k][0] == 'S' ||
		parse->map[k][0] == 'W' || parse->map[k][0] == 'E')
		{
			if (!parsetexture(parse->map[k], parse))
				ft_error("Error\nin texture\n");
		}
		else
			ft_error("Error\nin texture\n");
	}
	check_var(parse);
	parsemap(parse);
}
