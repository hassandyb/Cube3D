/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:10:21 by cgouiame          #+#    #+#             */
/*   Updated: 2024/01/19 13:26:51 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_after_newline(char *p)
{
	char	*stock;
	int		j;
	int		i;

	i = 0;
	while (p[i] != '\n')
	{
		if (p[i] == '\0')
			return (free(p), NULL);
		i++;
	}
	j = i + 1;
	while (p[i] != '\0')
		i++;
	stock = ft_substr(p, j, i - j);
	free(p);
	return (stock);
}

char	*ft_strjoin(char *p, char *buffer)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (p == NULL)
		p = ft_strdup("");
	result = (char *)malloc (ft_strlen (p) + ft_strlen (buffer) + 1);
	if (result == (NULL))
		return (NULL);
	while (p[i] != '\0')
	{
		result[i] = p[i];
		i++;
	}
	while (buffer[j] != '\0')
		result[i++] = buffer[j++];
	result[ft_strlen(p) + ft_strlen(buffer)] = '\0';
	free(p);
	return (result);
}

int	ft_newline(char *p)
{
	int	i;

	i = 0;
	if (p == NULL)
		return (0);
	while (p[i] != '\0')
	{
		if (p[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*result;
	static char	*p;
	int			x;

	x = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof (char));
	if (buffer == NULL)
		return (NULL);
	while (ft_strchr(p, '\n') == 0 && x > 0)
	{
		x = read (fd, buffer, BUFFER_SIZE);
		if (x == -1)
			return (free(p), free(buffer), NULL);
		buffer[x] = '\0';
		p = ft_strjoin(p, buffer);
	}
	free (buffer);
	result = ft_substr(p, 0, ft_newline(p) + 1);
	p = ft_after_newline(p);
	return (result);
}
