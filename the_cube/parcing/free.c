/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:30:35 by cgouiame          #+#    #+#             */
/*   Updated: 2024/01/20 18:51:59 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
 

char	*ft_erase(char *str)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	line = malloc(sizeof(char) * ft_strlen(str));
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && str[i] != ' ')
		i++;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i])
		line[j++] = str[i++];
	line[j] = '\0';
	return (free(str), line);
}

void	ft_free_mem(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

char	*skip_space(char *str)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	j = ft_strlen(str) - 1;
	while (str[j] && (str[j] == ' ' || str[j] == '\n'))
		j--;
	line = ft_substr(str, i, j - i + 1);
	return (free(str), line);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i])
		write(fd, &str[i++], 1);
}

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}
