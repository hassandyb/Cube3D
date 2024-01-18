/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:01:44 by hed-dyb           #+#    #+#             */
/*   Updated: 2024/01/18 14:01:40 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_mini_map_background(t_prime *prime)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++y < MINI_HEI)
	{
		x = -1;
		while (++x < MINI_WID)
		{
			ft_put_a_pixel(prime, x, y, 0xd3d3d3);
		}
	}
}

void	ft_mini_player_dir(t_prime *prime, int px, int py)
{
	double	dx;
	double	dy;
	int		i;
	int		x;
	int		y;

	dx = cos(prime->player.angle);
	dy = sin(prime->player.angle);
	i = 0;
	while (i < 15)
	{
		x = px + i * dx;
		y = py + i * dy;
		ft_put_a_pixel(prime, x, y, 0x012840);
		i++;
	}
}

void	ft_draw_player(t_prime *prime, int dx_mini, int dy_mini)
{
	int	px;
	int	py;

	px = (((MINI_WID / MINI_TILE) / 2) * MINI_TILE) + dx_mini;
	py = (((MINI_HEI / MINI_TILE) / 2) * MINI_TILE) + dy_mini;
	ft_put_a_pixel(prime, px, py, 0x011826);
	ft_put_a_pixel(prime, px + 1, py, 0x011826);
	ft_put_a_pixel(prime, px - 1, py, 0x011826);
	ft_put_a_pixel(prime, px, py + 1, 0x011826);
	ft_put_a_pixel(prime, px, py - 1, 0x011826);
	ft_put_a_pixel(prime, px + 2, py, 0x011826);
	ft_put_a_pixel(prime, px - 2, py, 0x011826);
	ft_put_a_pixel(prime, px, py + 2, 0x011826);
	ft_put_a_pixel(prime, px, py - 2, 0x011826);
	ft_put_a_pixel(prime, px + 1, py + 1, 0x011826);
	ft_put_a_pixel(prime, px - 1, py - 1, 0x011826);
	ft_put_a_pixel(prime, px - 1, py + 1, 0x011826);
	ft_put_a_pixel(prime, px + 1, py - 1, 0x011826);
	ft_mini_player_dir(prime, px, py);
}

void	ft_mini_player(t_prime *prime)
{
	int	dy_mini;
	int	dx_mini;
	int	y_tile;
	int	x_tile;

	y_tile = (long)prime->player.py % IMG_SIZE;
	x_tile = (long)prime->player.px % IMG_SIZE;
	dx_mini = (MINI_TILE - 1) * (x_tile) / (IMG_SIZE - 1);
	dy_mini = (MINI_TILE - 1) * (y_tile) / (IMG_SIZE - 1);
	ft_draw_player(prime, dx_mini, dy_mini);
}

void	ft_the_mini_map(t_prime *prime)
{
	ft_mini_map_background(prime);
	ft_mini_map_walls(prime);
	ft_mini_player(prime);
}
