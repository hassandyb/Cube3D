/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 11:49:41 by hed-dyb           #+#    #+#             */
/*   Updated: 2024/01/07 11:52:31 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void ft_update_hit_r1(t_prime *prime)
{
	if(prime->ray.l_len == 0)// could not hit a line
	{
		prime->ray.hit = 1;// hits a colom == the east wall
		return ;
	}	
	if(prime->ray.c_len == 0)// could not hit coloms
	{
		prime->ray.hit = 2;//  hits a line == the south wall
		return ;
	}
	if(prime->ray.c_len <= prime->ray.l_len)
		prime->ray.hit = 1;// hits the east wall 
	else
		prime->ray.hit = 2;// hits the south wall -->
	
}

void ft_update_hit_r2(t_prime *prime)
{
	if(prime->ray.l_len == 0)// cound not his a line  so it his a coloms == the weat west
	{
		prime->ray.hit = 3; 
		return ;
	}
	if(prime->ray.c_len == 0)// coud not hit a colom so it hit sthe line == hist the south wall
	{
		prime->ray.hit = 2;
		return ;
	}
	
	if(prime->ray.l_len <=  prime->ray.c_len)
		prime->ray.hit = 2; // hits south wall
	else
		prime->ray.hit = 3;// hits the weat wall  <==
}

void ft_update_hit_r3(t_prime *prime)
{
	if(prime->ray.l_len == 0)// could not hit a line it his a columon == west wall
	{
		prime->ray.hit = 3;
		return ;
	}
	if(prime->ray.c_len == 0)// could not hit a coloms so it will his a line == the north wall
	{
		prime->ray.hit = 4;
		return ;
	}
	if(prime->ray.c_len <= prime->ray.l_len)// hit the colomn == the weat wall
		prime->ray.hit = 3;
	else
		prime->ray.hit = 4;
}

void ft_update_hit_r4(t_prime *prime)
{
	if(prime->ray.c_len == 0)// could not hit a colum == hits a ine == the north wall 
	{
		prime->ray.hit = 4;
		return ;
	}
	if(prime->ray.l_len == 0)// could not hit a line == hits a wall == the east wall
	{
		prime->ray.hit = 1;
		return ;
	}
	if(prime->ray.l_len < prime->ray.c_len)
		prime->ray.hit = 4;
	else
		prime->ray.hit = 1;
}





