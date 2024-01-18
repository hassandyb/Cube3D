/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:24:37 by hed-dyb           #+#    #+#             */
/*   Updated: 2024/01/18 16:20:33 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

bool	ft_the_easy_cases(t_prime *prime)
{
	if (prime->ray.r_angle == 0 || prime->ray.r_angle == M_PI)
	{
		prime->wall.x_tile = (long)prime->player.py % IMG_SIZE;
		return (true);
	}
	if (prime->ray.r_angle == (M_PI / 2) \
		|| prime->ray.r_angle == (3 * M_PI / 2))
	{
		prime->wall.x_tile = (long)prime->player.px % IMG_SIZE;
		return (true);
	}
	return (false);
}

long	ft_l_on_r1(t_prime *prime)
{
	double	alpha;
	long	l;

	alpha = prime->ray.r_angle;
	if (prime->ray.hit == HIT_EAST)
		l = prime->player.py + (prime->ray.len * sin(alpha));
	else
		l = prime->player.px + (prime->ray.len * cos(alpha));
	return (l);
}

long	ft_l_on_r2(t_prime *prime)
{
	double	alpha;
	long	l;

	alpha = prime->ray.r_angle - (M_PI / 2);
	if (prime->ray.hit == HIT_SOUTH)
		l = prime->player.px - (prime->ray.len * sin(alpha));
	else
		l = prime->player.py + (prime->ray.len * cos(alpha));
	return (l);
}

long	ft_l_on_r3(t_prime *prime)
{
	double	alpha;
	long	l;

	alpha = prime->ray.r_angle - M_PI;
	if (prime->ray.hit == HIT_WEST)
		l = prime->player.py - (prime->ray.len * sin (alpha));
	else
		l = prime->player.px - (prime->ray.len * cos(alpha));
	return (l);
}

long	ft_l_on_r4(t_prime *prime)
{
	double	alpha;
	long	l;

	alpha = prime->ray.r_angle - (3 * M_PI / 2);
	if (prime->ray.hit == HIT_NORTH)
		l = prime->player.px + (prime->ray.len * sin(alpha));
	else
		l = prime->player.py - (prime->ray.len * cos (alpha));
	return (l);
}
