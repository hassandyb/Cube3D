/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:01:59 by hed-dyb           #+#    #+#             */
/*   Updated: 2024/01/18 14:00:52 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_draw_mini_tile(t_prime *prime, int i_mini, int j_mini)
{
	int	x;
	int	y;
	int	save;
	int	i;
	int	j;

	i = -1;
	j = -1;
	x = i_mini * MINI_TILE;
	save = x;
	y = j_mini * MINI_TILE;
	while (++j < MINI_TILE)
	{
		i = -1;
		x = save;
		while (++i < MINI_TILE)
		{
			ft_put_a_pixel(prime, x, y, 0x343534);
			x++;
		}
		y++;
	}
}

void	ft_first_tile_cord(t_prime *prime, int *i_map, int *j_map)
{
	*j_map = prime->player.py / IMG_SIZE;
	*i_map = prime->player.px / IMG_SIZE;
	*i_map -= (MINI_COLS / 2);
	*j_map -= (MINI_LINES / 2);
}

bool	ft_valid_drawing(t_prime *prime, int i_map, int j_map)
{
	if (i_map < 0 || j_map < 0)
		return (true);
	if (i_map >= (int)prime->cols || j_map >= (int)prime->lines)
		return (true);
	if (prime->parse->map[j_map][i_map] == '1')
		return (true);
	if (prime->parse->map[j_map][i_map] == ' ')
		return (true);
	if (prime->parse->map[j_map][i_map] == '\0')
		return (true);
	return (false);
}

void	ft_mini_map_walls(t_prime *prime)
{
	int	j_mini;
	int	i_mini;
	int	j_map;
	int	i_map;
	int	save;

	ft_first_tile_cord(prime, &i_map, &j_map);
	save = i_map;
	i_mini = -1;
	j_mini = -1;
	while (++j_mini < MINI_LINES)
	{
		i_mini = -1;
		while (++i_mini < MINI_COLS)
		{
			if (ft_valid_drawing(prime, i_map, j_map) == true)
				ft_draw_mini_tile(prime, i_mini, j_mini);
			i_map ++;
		}
		i_map = save;
		j_map ++;
	}
}
