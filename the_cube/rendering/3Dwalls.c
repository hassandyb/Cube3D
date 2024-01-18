/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3Dwalls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:20:48 by hed-dyb           #+#    #+#             */
/*   Updated: 2024/01/18 15:01:32 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_find_x_tile(t_prime *prime)
{
	long	l;

	if (ft_the_easy_cases(prime) == true)
		return ;
	if (prime->ray.r_angle > 0 && prime->ray.r_angle < (M_PI / 2))
		l = ft_l_on_r1(prime);
	if (prime->ray.r_angle > (M_PI / 2) && prime->ray.r_angle < M_PI)
		l = ft_l_on_r2(prime);
	if (prime->ray.r_angle > M_PI && prime->ray.r_angle < (3 * M_PI / 2))
		l = ft_l_on_r3(prime);
	if (prime->ray.r_angle > (3 * M_PI / 2) && prime->ray.r_angle < (2 * M_PI))
		l = ft_l_on_r4(prime);
	prime->wall.x_tile = l % IMG_SIZE;
}

t_img	ft_which_texture(t_prime *prime)
{
	t_img	img;

	if (prime->ray.hit == HIT_EAST)
		img = prime->imgs[EAST];
	if (prime->ray.hit == HIT_SOUTH)
		img = prime->imgs[SOUTH];
	if (prime->ray.hit == HIT_WEST)
		img = prime->imgs[WEST];
	if (prime->ray.hit == HIT_NORTH)
		img = prime->imgs[NORTH];
	return (img);
}

unsigned int	ft_which_color(t_prime *prime, t_img img, int count)
{
	int				x_img;
	int				y_img;
	long			pos;
	unsigned int	color;

	if (prime->wall.x_tile < 0)
		prime->wall.x_tile = 0;
	x_img = ((img.wid - 1) * prime->wall.x_tile) / (IMG_SIZE - 1);
	y_img = ((img.hei - 1) * count) / (prime->wall.h - 1);
	pos = ((y_img * img.size_line) + (x_img * img.bits_per_pixel / 8));
	color = (*(unsigned int *)(img.ad + pos));
	return (color);
}

void	ft_show_the_colom(t_prime *prime, double x_screen)
{
	int				y_screen;
	t_img			img;
	int				count;
	unsigned int	color;

	y_screen = ((SCREEN_HEI - prime->wall.h) / 2) - 1;
	count = 0;
	img = ft_which_texture(prime);
	if (y_screen < 0)
		y_screen = 0;
	while (count < prime->wall.h)
	{
		if (y_screen >= SCREEN_HEI)
			return ;
		color = ft_which_color(prime, img, count);
		ft_put_a_pixel(prime, x_screen, y_screen, color);
		y_screen++;
		count ++;
	}
}

void	ft_length_on_screen(t_prime *prime)
{
	double	deltateta;

	deltateta = prime->ray.r_angle - prime->player.angle;
	prime->wall.real = prime->ray.len * cos(deltateta);
	prime->wall.h = (IMG_SIZE * prime->wall.d) / prime->wall.real;
}
