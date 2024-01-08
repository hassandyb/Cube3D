/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castingr1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 11:08:19 by hed-dyb           #+#    #+#             */
/*   Updated: 2024/01/07 11:55:56 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"



void ft_special_case_r1(t_prime *prime)
{
	double pt_x;
	double pt_y;
	double dx;
	int i;

	i = prime->player.px / IMG_SIZE;
	pt_x = (i + 1) * IMG_SIZE;
	pt_y = prime->player.py;
	dx = pt_x - prime->player.px;
	if(ft_is_intersection_point(prime, pt_x, pt_y) == true)
		prime->ray.len = dx;
	else
	{
		prime->ray.len = dx;
		while(1)
		{
			prime->ray.len += IMG_SIZE;
			pt_x += IMG_SIZE;
			if(ft_is_intersection_point(prime, pt_x, pt_y) == true)
				return ;
		}
	}
}

void ft_update_line_r1(t_prime *prime)
{
	int j;
	double alpha;

	alpha = prime->ray.r_angle;
	j = prime->player.py / IMG_SIZE;		
	prime->ray.deltay = ((j + 1) * IMG_SIZE) - prime->player.py;
	prime->ray.deltax = prime->ray.deltay / tan(alpha);

	prime->ray.first = prime->ray.deltay / sin(alpha);
	prime->ray.periodic = IMG_SIZE / sin(alpha);

}

void ft_find_l_len_r1(t_prime *prime)
{
	double pt_x;
	double pt_y;
	double alpha;

	alpha = prime->ray.r_angle;
	pt_x = prime->player.px + prime->ray.deltax;
	pt_y = prime->player.py + prime->ray.deltay;
	if(ft_valid_i(prime, pt_x) == false)
		return;
	if(ft_is_intersection_point(prime, pt_x, pt_y) == true)
		prime->ray.l_len = prime->ray.first;
	else
	{
		prime->ray.l_len = prime->ray.first;
		while(1)
		{
			pt_x += (prime->ray.periodic * cos(alpha));
			pt_y += IMG_SIZE;
			prime->ray.l_len += prime->ray.periodic;
			if(ft_valid_i(prime, pt_x) == false)
				return;
			if(ft_is_intersection_point(prime, pt_x, pt_y) == true)
				return ;
		}
	}
}

void ft_update_col_r1(t_prime *prime)
{
	int i;
	double alpha;

	i = prime->player.px / IMG_SIZE;
	prime->ray.deltax = ((i + 1) * IMG_SIZE) - prime->player.px;
	alpha = prime->ray.r_angle;

	prime->ray.deltay = prime->ray.deltax * tan(alpha);
	prime->ray.first = prime->ray.deltay / sin (alpha);
	prime->ray.periodic = IMG_SIZE / cos(alpha);
}

void ft_find_c_len_r1(t_prime *prime)
{
	double pt_x;
	double pt_y;
	double alpha;

	alpha = prime->ray.r_angle;
	pt_x = prime->player.px + prime->ray.deltax;
	pt_y = prime->player.py + prime->ray.deltay;
	if(ft_valid_j(prime, pt_y) == false)
		return;
	if(ft_is_intersection_point(prime, pt_x, pt_y) == true)
		prime->ray.c_len = prime->ray.first;
	else
	{
		prime->ray.c_len = prime->ray.first;
		while(1)
		{
			pt_x += IMG_SIZE;
			pt_y += (prime->ray.periodic * sin(alpha));
			prime->ray.c_len += prime->ray.periodic;
			if(ft_valid_j(prime, pt_y) == false)
				return;
			if(ft_is_intersection_point(prime, pt_x, pt_y) == true)
				return ;
		}
	}
}

