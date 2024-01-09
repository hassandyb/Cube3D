/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castingr2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 11:56:06 by hed-dyb           #+#    #+#             */
/*   Updated: 2024/01/07 11:56:24 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"


void ft_special_case_r2(t_prime *prime)
{
	double pt_x;
	double pt_y;
	double dy;
	int j;

	j = prime->player.py / IMG_SIZE;
	pt_y = (j + 1) * IMG_SIZE;
	pt_x = prime->player.px;
	dy = pt_y - prime->player.py;
	if(ft_is_intersection_point(prime, pt_x, pt_y) == true)
		prime->ray.len = dy;
	else
	{
		prime->ray.len = dy;
		while(1)
		{
			prime->ray.len += IMG_SIZE;
			pt_y += IMG_SIZE;
			if(ft_is_intersection_point(prime, pt_x, pt_y) == true)
				return ;
		}
	}



}

void ft_ft_update_line_r2(t_prime *prime)
{
	double alpha;
	int j;
	alpha = prime->ray.r_angle - (M_PI / 2);
	j = prime->player.py / IMG_SIZE;
	prime->ray.deltay = ((j + 1) * IMG_SIZE) - prime->player.py;
	prime->ray.deltax = prime->ray.deltay * tan(alpha);

	prime->ray.first = prime->ray.deltay / cos(alpha);
	prime->ray.periodic = IMG_SIZE / cos(alpha);
	
}

void ft_find_l_len_r2(t_prime *prime)
{
	double pt_x;
	double pt_y;
	double alpha;

	alpha = prime->ray.r_angle - (M_PI / 2);
	pt_x = prime->player.px - prime->ray.deltax;
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
			pt_x -= prime->ray.periodic * sin(alpha);
			pt_y += IMG_SIZE;
			prime->ray.l_len += prime->ray.periodic;
			if(ft_valid_i(prime, pt_x) == false)
				return ;
			if(ft_is_intersection_point(prime, pt_x, pt_y) == true)
				return ;
		}
	}
}

void ft_update_col_r2(t_prime *prime)
{
	int i;
	double alpha;

	alpha = prime->ray.r_angle - (M_PI / 2);
	i = prime->player.px / IMG_SIZE;
	prime->ray.deltax = prime->player.px - (i * IMG_SIZE);
	prime->ray.deltay = prime->ray.deltax / tan(alpha);
	prime->ray.first = prime->ray.deltax / sin (alpha);
	prime->ray.periodic = IMG_SIZE / sin (alpha);


}

void ft_find_c_len_r2(t_prime *prime)
{
	double pt_x;
	double pt_y;
	double alpha;

	alpha = prime->ray.r_angle - (M_PI / 2);
	pt_x = prime->player.px - prime->ray.deltax - 5;// -5 or -10 ... just less than IMG_SIZE why?? cause we wanna check the square on the lefe not the square we get !!
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
			pt_x -= IMG_SIZE;

			pt_y += prime->ray.periodic * cos(alpha);
			prime->ray.c_len += prime->ray.periodic;
			if(ft_valid_j(prime, pt_y) == false)
				return ;
			if(ft_is_intersection_point(prime, pt_x, pt_y) == true)// 
				return ;
			
		}
	}
}

