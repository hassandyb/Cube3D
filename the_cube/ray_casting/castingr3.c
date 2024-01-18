/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castingr3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 11:56:34 by hed-dyb           #+#    #+#             */
/*   Updated: 2024/01/17 21:31:53 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_special_case_r3(t_prime *prime)
{
	double	pt_x;
	double	pt_y;
	double	dx;
	int		i;

	i = prime->player.px / IMG_SIZE;
	pt_x = (i * IMG_SIZE) - 5;
	pt_y = prime->player.py;
	dx = prime->player.px - (i * IMG_SIZE);
	if (ft_is_intersection_point(prime, pt_x, pt_y) == true)
		prime->ray.len = dx;
	else
	{
		prime->ray.len = dx;
		while (1)
		{
			pt_x -= IMG_SIZE;
			prime->ray.len += IMG_SIZE;
			if (ft_is_intersection_point(prime, pt_x, pt_y) == true)
				return ;
		}
	}
}

void	ft_update_line_r3(t_prime *prime)
{
	double	alpha;
	int		j;

	alpha = prime->ray.r_angle - M_PI;
	j = prime->player.py / IMG_SIZE;
	prime->ray.deltay = prime->player.py - (j * IMG_SIZE);
	prime->ray.deltax = prime->ray.deltay / tan (alpha);
	prime->ray.first = prime->ray.deltay / sin (alpha);
	prime->ray.periodic = IMG_SIZE / sin (alpha);
}

void	ft_find_l_len_r3(t_prime *prime)
{
	double	pt_x;
	double	pt_y;
	double	alpha;

	alpha = prime->ray.r_angle - M_PI;
	pt_x = prime->player.px - prime->ray.deltax;
	pt_y = prime->player.py - prime->ray.deltay -5 ;
	if (ft_valid_i(prime, pt_x) == false)
		return ;
	if (ft_is_intersection_point(prime, pt_x, pt_y) == true)
		prime->ray.l_len = prime->ray.first;
	else
	{
		prime->ray.l_len = prime->ray.first;
		while (1)
		{
			pt_y -= IMG_SIZE;
			pt_x -= IMG_SIZE / tan(alpha);
			prime->ray.l_len += prime->ray.periodic;
			if (ft_valid_i(prime, pt_x) == false)
				return ;
			if (ft_is_intersection_point(prime, pt_x, pt_y) == true)
				return ;
		}
	}
}

void	ft_update_col_r3(t_prime *prime)
{
	int		i;
	double	alpha;

	alpha = prime->ray.r_angle - M_PI;
	i = prime->player.px / IMG_SIZE;
	prime->ray.deltax = prime->player.px - (i * IMG_SIZE);
	prime->ray.deltay = prime->ray.deltax * tan (alpha);
	prime->ray.first = prime->ray.deltax / cos(alpha);
	prime->ray.periodic = IMG_SIZE / cos (alpha);
}

void	ft_find_c_len_r3(t_prime *prime)
{
	double	pt_x;
	double	pt_y;
	double	alpha;

	alpha = prime->ray.r_angle;
	pt_x = prime->player.px - prime->ray.deltax - 5;
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
			pt_x -= IMG_SIZE;
			pt_y -= (IMG_SIZE * tan(alpha));
			prime->ray.c_len += prime->ray.periodic;
			if (ft_valid_j(prime, pt_y) == false)
				return ;
			if (ft_is_intersection_point(prime, pt_x, pt_y) == true)
				return ;
		}
	}
}
