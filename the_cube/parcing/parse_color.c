/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:56:32 by cgouiame          #+#    #+#             */
/*   Updated: 2024/01/22 17:09:00 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**check_and_split(char *str, int *flag2)
{
	int		i;
	char	**tab;

	i = -1;
	while (str[++i])
		if (str[i] == ',')
			(*flag2)++;
	if (*flag2 != 2)
		return (NULL);
	tab = ft_split(str, ',');
	i = 0;
	while (tab[i])
		i++;
	if (i != 3)
	{
		ft_free_mem(tab);
		return (NULL);
	}
	return (tab);
}

int	parse_color(char **tab, t_parse *parse, int flag)
{
	int	i;
	int	cn[3];

	i = 0;
	while (tab[i])
	{
		cn[i] = my_atoi(tab[i]);
		if (cn[i] < 0 || cn[i] > 255)
		{
			ft_free_mem(tab);
			return (-1);
		}
		i++;
	}
	if (flag == 0)
		parse->f = cn[0] << 16 | cn[1] << 8 | cn[2];
	else if (flag == 1)
		parse->c = cn[0] << 16 | cn[1] << 8 | cn[2];
	ft_free_mem(tab);
	return (1);
}

int	parsemycolor(char *str, t_parse *parse, int flag)
{
	int		flag2;
	char	**tab;

	flag2 = 0;
	tab = check_and_split(str, &flag2);
	if (tab == NULL)
		return (-1);
	return (parse_color(tab, parse, flag));
}
