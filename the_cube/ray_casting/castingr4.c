/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castingr4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 11:56:58 by hed-dyb           #+#    #+#             */
/*   Updated: 2024/01/17 21:26:17 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_special_case_r4(t_prime *prime)
{
	double	pt_x;
	double	pt_y;
	double	dy;
	int		j;

	j = prime->player.py / IMG_SIZE;
	dy = prime->player.py - (j * IMG_SIZE);
	pt_y = (j * IMG_SIZE) - 5;
	pt_x = prime->player.px;
	if (ft_is_intersection_point(prime, pt_x, pt_y) == true)
		prime->ray.len = dy;
	else
	{
		prime->ray.len = dy;
		while (1)
		{
			pt_y -= IMG_SIZE;
			prime->ray.len += IMG_SIZE;
			if (ft_is_intersection_point(prime, pt_x, pt_y) == true)
				return ;
		}
	}
}

void	ft_update_line_r4(t_prime *prime)
{
	double	alpha;
	int		j;

	alpha = prime->ray.r_angle - (3 * M_PI / 2);
	j = prime->player.py / IMG_SIZE;
	prime->ray.deltay = prime->player.py - (j * IMG_SIZE);
	prime->ray.deltax = prime->ray.deltay * tan (alpha);
	prime->ray.first = prime->ray.deltay / cos(alpha);
	prime->ray.periodic = IMG_SIZE / cos (alpha);
}

void	ft_find_l_len_r4(t_prime *prime)
{
	double	pt_x;
	double	pt_y;
	double	alpha;

	alpha = prime->ray.r_angle - (3 * M_PI / 2);
	pt_x = prime->player.px + prime->ray.deltax;
	pt_y = prime->player.py - prime->ray.deltay - 5;
	if (ft_valid_i(prime, pt_x) == false)
		return ;
	if (ft_is_intersection_point(prime, pt_x, pt_y) == true)
		prime->ray.l_len = prime->ray.first;
	else
	{
		prime->ray.l_len = prime->ray.first;
		while (1)
		{
			pt_x += prime->ray.periodic * sin (alpha);
			pt_y -= IMG_SIZE;
			prime->ray.l_len += prime->ray.periodic;
			if (ft_valid_i(prime, pt_x) == false)
				return ;
			if (ft_is_intersection_point(prime, pt_x, pt_y) == true)
				return ;
		}
	}
}

void	ft_update_col_r4(t_prime *prime)
{
	int		i;
	double	alpha;

	alpha = prime->ray.r_angle - (3 * M_PI / 2);
	i = prime->player.px / IMG_SIZE;
	prime->ray.deltax = (i + 1) * IMG_SIZE - prime->player.px;
	prime->ray.deltay = prime->ray.deltax / tan (alpha);
	prime->ray.first = prime->ray.deltax / sin (alpha);
	prime->ray.periodic = IMG_SIZE / sin (alpha);
}

void	ft_find_c_len_r4(t_prime *prime)
{
	double	pt_x;
	double	pt_y;
	double	alpha;

	alpha = prime->ray.r_angle - (3 * M_PI / 2);
	pt_x = prime->player.px + prime->ray.deltax;
	pt_y = prime->player.py - prime->ray.deltay;
	if (ft_valid_j(prime, pt_y) == false)
		return ;
	if (ft_is_intersection_point(prime, pt_x, pt_y) == true)
		prime->ray.c_len = prime->ray.first;
	else
	{
		prime->ray.c_len = prime->ray.first;
		while (1)
		{
			pt_x += IMG_SIZE;
			pt_y -= (IMG_SIZE / tan(alpha));
			prime->ray.c_len += prime->ray.periodic;
			if (ft_valid_j(prime, pt_y) == false)
				return ;
			if (ft_is_intersection_point(prime, pt_x, pt_y) == true)
				return ;
		}
	}
}
