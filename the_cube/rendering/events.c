/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:42:38 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/12/31 13:43:46 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"



int ft_press_events(int key, t_prime *prime)
{
	if(key == KEY_W)
		prime->fb_status = 1;
	if(key == KEY_S)
		prime->fb_status = -1;
	if(key == KEY_D)
		prime->rl_status = 1;
	if(key == KEY_A)
		prime->rl_status = -1;
	

	if(key == KEY_RIGHT_ARROW)
		prime->rotate_status = 1;
	if(key == KEY_LEFT_ARROW)
		prime->rotate_status = -1;
	// ----
	
	return 0;
}

int ft_release_events(int key, t_prime *prime)
{
	if(key == KEY_W || key == KEY_S)
		prime->fb_status = 0;
	if(key == KEY_A || key == KEY_D)
		prime->rl_status = 0;
	if(key == KEY_RIGHT_ARROW || key == KEY_LEFT_ARROW)
		prime->rotate_status = 0;
	return 0;
}
