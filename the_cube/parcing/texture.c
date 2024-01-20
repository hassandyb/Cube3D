/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:29:02 by cgouiame          #+#    #+#             */
/*   Updated: 2024/01/19 18:29:52 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	size_t	i;
	char	*p;

	i = 0;
	p = (char *)malloc ((ft_strlen(s1) + 1) * sizeof(char));
	if (p == NULL)
		return (0);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (1);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (1);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

int	parsetexture(char *str, t_parse *parse)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	tab = ft_split(str, ' ');
	j = 0;
	while (tab[j])
		j++;
	if (j != 2)
		return (0);
	if (!ft_strcmp(tab[0], "NO"))
		parse->no = ft_strdup(tab[1]);
	else if (!ft_strcmp(tab[0], "SO"))
		parse->so = ft_strdup(tab[1]);
	else if (!ft_strcmp(tab[0], "WE"))
		parse->we = ft_strdup(tab[1]);
	else if (!ft_strcmp(tab[0], "EA"))
		parse->ea = ft_strdup(tab[1]);
	else
		return (0);
	ft_free_mem(tab);
	return (1);
}
