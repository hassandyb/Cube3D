/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:58:48 by cgouiame          #+#    #+#             */
/*   Updated: 2024/01/22 20:02:27 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_norm1(int len)
{
	char	*line;
	int		i;

	line = ft_strdup("");
	i = -1;
	while (++i < len)
		line = ft_strjoin(line, " ");
	return (line);
}

char	**map_rectangular(t_parse *parse, char **tab, int len)
{
	int		k;
	int		i;
	int		j;
	char	*line;

	i = 5;
	k = -1;
	while (parse->map[++i])
	{
		j = -1;
		line = ft_strdup("");
		if (parse->map[i][ft_strlen(parse->map[i]) - 1] == '\n')
			parse->map[i][ft_strlen(parse->map[i]) - 1] = '\0';
		while (++j < len - ft_strlen(parse->map[i]) - 1)
			line = ft_strjoin(line, " ");
		tab[++k] = ft_strjoin(ft_strdup(parse->map[i]), line);
		free(line);
	}
	tab[++k] = ft_norm1(len);
	free(tab[k]);
	tab[k] = NULL;
	parse->mapsize = k;
	parse->lenstr = len;
	ft_free_mem(parse->map);
	return (tab);
}

void	ft_norm(t_parse *parse, int i, int j)
{
	if (parse->map[i][j] != '1' && parse->map[i][j] != ' ' &&
	parse->map[i][j] != '0' && parse->map[i][j] != 'N' &&
	parse->map[i][j] != 'S' && parse->map[i][j] != 'W'
	&& parse->map[i][j] != 'E')
		ft_error("Error\nMap is not valid\n");
}

void	ft_check_map(t_parse *parse, int i, int j)
{
	ft_norm(parse, i, j);
	if (parse->map[i][j] == '0' || parse->map[i][j] == 'N'
	|| parse->map[i][j] == 'S' || parse->map[i][j] == 'W'
	|| parse->map[i][j] == 'E')
	{
		if (i == 0 || j == parse->lenstr - 1 || j == 0
			|| i == parse->mapsize - 1)
			ft_error("Error\nMap is not closed\n");
		if (parse->map[i][j + 1] == ' ' || parse->map[i][j - 1] == ' '
		|| parse->map[i + 1][j] == ' ' || parse->map[i - 1][j] == ' '
		|| parse->map[i][j + 1] == '\0' || parse->map[i][j - 1] == '\0'
		|| parse->map[i + 1][j] == '\0' || parse->map[i - 1][j] == '\0')
			ft_error("Error\nMap is not closeed\n");
		if (parse->map[i][j] == 'N' || parse->map[i][j] == 'S'
		|| parse->map[i][j] == 'W' || parse->map[i][j] == 'E')
		{
			if (parse->flag == 1)
				ft_error("Error\nMultiple players\n");
			parse->flag = 1;
			parse->px = i;
			parse->py = j;
			parse->p = parse->map[i][j];
			parse->map[i][j] = '0';
		}
	}
}

void	parsemap(t_parse *parse)
{
	int		i;
	int		j;
	int		len;
	char	**tab;

	len = get_longest_line(parse->map, &i);
	tab = malloc(sizeof(char *) * (i - 5));
	if (!tab)
		ft_error("Error\nMalloc failed\n");
	tab = map_rectangular(parse, tab, len);
	i = -1;
	parse->flag = 0;
	parse->map = tab;
	while (parse->map[++i])
	{
		j = 0;
		if (is_empty(parse->map[i]))
			break ;
		while (parse->map[i][j])
			ft_check_map(parse, i, j++);
	}
	if (parse->flag == 0)
		ft_error("Error\nNo map or No player\n");
}
