/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:19:06 by cgouiame          #+#    #+#             */
/*   Updated: 2024/01/20 20:39:32 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsecolor(t_parse *parse, int k)
{
	if (parse->map[k][0] == 'F')
	{
		parse->map[k] = ft_erase(parse->map[k]);
		if (parsemycolor(parse->map[k], parse, 0) == -1)
			ft_error("Error: in floor\n");
	}
	else if (parse->map[k][0] == 'C')
	{
		parse->map[k] = ft_erase(parse->map[k]);
		if (parsemycolor(parse->map[k], parse, 1) == -1)
			ft_error("Error: in ceiling\n");
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

char	**map_rectangular(t_parse *parse, char **tab, int len)
{
	int		k;
	int		i;
	int		j;
	char	*line;

	line = NULL;
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
	
	line = ft_strdup("");
	
	i = -1;
	while (++i < len)
		line = ft_strjoin(line, " ");
	tab[++k] = ft_strdup(line);
	free(line);
	free(tab[k]);
	tab[k] = NULL;
	parse->mapsize = k;
	parse->lenstr = len;
	ft_free_mem(parse->map);
	return (tab);
}

void	ft_check_map(t_parse *parse, int i, int j)
{
	if (parse->map[i][j] != '1' && parse->map[i][j] != ' ' &&
	parse->map[i][j] != '0' && parse->map[i][j] != 'N' &&
	parse->map[i][j] != 'S' && parse->map[i][j] != 'W'
	&& parse->map[i][j] != 'E')
		ft_error("Error: Map1\n");
}

void	ft_norm(t_parse *parse, int i, int j)
{
	ft_check_map(parse, i, j);
	if (parse->map[i][j] == '0' || parse->map[i][j] == 'N'
	|| parse->map[i][j] == 'S' || parse->map[i][j] == 'W'
	|| parse->map[i][j] == 'E')
	{
		if (i == 0 || j == parse->lenstr - 1 || j == 0 || i == parse->mapsize - 1)
			ft_error("Error: Map is not closedddddd\n");
		if (parse->map[i][j + 1] == ' ' || parse->map[i][j - 1] == ' '
		|| parse->map[i + 1][j] == ' ' || parse->map[i - 1][j] == ' ')
			ft_error("Error: Map is not closed-\n");
		if (parse->map[i][j] == 'N' || parse->map[i][j] == 'S'
		|| parse->map[i][j] == 'W' || parse->map[i][j] == 'E')
		{
			if (parse->flag == 1)
				ft_error("Error: Map2\n");
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
		ft_error("Error: malloc failed\n");
	
	tab = map_rectangular(parse, tab, len);
	i = -1;
	parse->flag = 0;
	parse->map = tab;
	while (parse->map[++i])
	{
		j = 0;
		if (is_empty(parse->map[i]))
			break;
		while (parse->map[i][j])
			ft_norm(parse, i, j++);
	}
	
	if (parse->flag == 0)
		ft_error("Error: Map3\n");
	
}

void	check_var(t_parse *parse)
{
	if (parse->no == NULL || parse->so == NULL || parse->we == NULL
		|| parse->ea == NULL || parse->f == -1 || parse->c == -1)
		ft_error("Error: in texture1\n");
}

void	ft_parse_cub(int fd, t_parse *parse, char *av)
{
	int		k;

	parse->map = read_map(fd, av, parse);
	if (parse->mapsize < 6)
		ft_error("Error: Map is emppty\n");
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
				ft_error("Error: in texture2\n");
		}
		else
			ft_error("Error: in texture3\n");
	}
	check_var(parse);
	
	parsemap(parse);
	
}