/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:22:43 by cgouiame          #+#    #+#             */
/*   Updated: 2024/01/19 18:26:05 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	slen;
	size_t	i;

	i = 0;
	if (s == NULL || s[i] == '\0')
		return (NULL);
	slen = ft_strlen(s);
	p = (char *)malloc(len + 1);
	if (p == NULL)
		return (NULL);
	while (s[i + start] != '\0' && i < len)
	{
		p[i] = s[i + start];
		i++;
	}
	p[i] = '\0';
	return (p);
}

int	is_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	getsize(int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (i);
}

int	my_atoi(char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		return (-1);
	if (!str[i] || str[i] < '0' || str[i] > '9')
		return (-1);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + (str[i++] - '0');
	while (str[i] && (str[i] == ' ' || str[i] == '\n'))
		i++;
	if (str[i])
		return (-1);
	return (nb);
}
