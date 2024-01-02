/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:44:48 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/12/31 14:46:09 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void ft_full_cords_if_possible(t_prime *prime, double tox, double toy)
{
	int i;
	int j;

	i = (prime->player.px + tox) / IMG_SIZE;
	j = (prime->player.py + toy) / IMG_SIZE;
	// wall collision
	if(ft_wall_collision_case(prime, i, j) == true)
		return;



	if(prime->parse->map[j][i] == '0' )// change it to equal to 0
	{
		prime->player.px += tox;
		prime->player.py += toy;
	}

}

void ft_first_range(t_prime *prime)
{
	double dx;
	double dy;
	double alpha;
	alpha = prime->player.angle;
	dx = MOVE_DESTANCE * cos(alpha);
	dy = MOVE_DESTANCE * sin(alpha);

	if (prime->fb_status == 1)
		ft_full_cords_if_possible(prime, dx, dy);
	if(prime->fb_status == -1)
		ft_full_cords_if_possible(prime, -dx, -dy);
	if(prime->rl_status == 1)
		ft_full_cords_if_possible(prime, -dy, dx);
	if(prime->rl_status == -1)
		ft_full_cords_if_possible(prime, dy, -dx);
}

void ft_second_range(t_prime *prime)
{
	double dx;
	double dy;
	double alpha;

	alpha = prime->player.angle - (M_PI / 2);
	dx = MOVE_DESTANCE * sin(alpha);
	dy = MOVE_DESTANCE * cos(alpha);
	if(prime->fb_status == 1)
	{
		ft_full_cords_if_possible(prime, -dx, dy);
	}
	if(prime->fb_status == -1)
	{
		ft_full_cords_if_possible(prime, dx, -dy);
	}
	if(prime->rl_status == 1)
	{
		ft_full_cords_if_possible(prime, -dy, -dx);

	}
	if(prime->rl_status == -1)
	{
		ft_full_cords_if_possible(prime, dy, dx);
	}
}

void ft_third_range(t_prime *prime)
{
	double dx;
	double dy;
	double alpha;

	alpha = prime->player.angle - M_PI;
	dx = MOVE_DESTANCE * cos(alpha);
	dy = MOVE_DESTANCE * sin(alpha);
	if(prime->fb_status == 1)
	{
		ft_full_cords_if_possible(prime, -dx, -dy);
	}
	if(prime->fb_status == -1)
	{
		ft_full_cords_if_possible(prime, dx, dy);
	}
	if(prime->rl_status == 1)
	{
		ft_full_cords_if_possible(prime, dy, -dx);
	}
	if(prime->rl_status == -1)
	{
		ft_full_cords_if_possible(prime, -dy, dx);
	}
}

void ft_fourth_range(t_prime *prime)
{
	double dx;
	double dy;
	double alpha;

	alpha = prime->player.angle - (3 * M_PI / 2);
	dx = MOVE_DESTANCE * sin (alpha);
	dy = MOVE_DESTANCE * cos (alpha);
	if(prime->fb_status == 1)
	{
		ft_full_cords_if_possible(prime, dx, -dy);
	}
	if(prime->fb_status == -1)
	{
		ft_full_cords_if_possible(prime, -dx, dy);
	}
	if(prime->rl_status == 1)
	{
		ft_full_cords_if_possible(prime, dy, dx);
	}
	if(prime->rl_status == -1)
	{
		ft_full_cords_if_possible(prime, -dy, -dx);
	}
}

