/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:42:38 by hed-dyb           #+#    #+#             */
/*   Updated: 2024/01/20 18:06:40 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_clean_exit(t_prime *prime)
{
	if(prime->parse->map)
		ft_free_mem(prime->parse->map);
	if(prime->parse->no)
		free(prime->parse->no);
	if(prime->parse->so)
		free(prime->parse->so);
	if(prime->parse->we)
		free(prime->parse->we);
	if(prime->parse->ea)
		free(prime->parse->ea);
	if(prime->mlx_ptr != NULL && prime->img_ptr != NULL)
		mlx_destroy_image(prime->mlx_ptr, prime->img_ptr);
	if(prime->mlx_ptr != NULL && prime->win_ptr)
		mlx_destroy_window(prime->mlx_ptr, prime->win_ptr);
	printf("Game over.\n");
	exit(1);
}

int	ft_press_events(int key, t_prime *prime)
{
	if (key == KEY_W)
		prime->fb_status = 1;
	if (key == KEY_S)
		prime->fb_status = -1;
	if (key == KEY_D)
		prime->rl_status = 1;
	if (key == KEY_A)
		prime->rl_status = -1;
	if (key == KEY_RIGHT_ARROW)
		prime->rotate_status = 1;
	if (key == KEY_LEFT_ARROW)
		prime->rotate_status = -1;
	if (key == KEY_ESC)
		ft_clean_exit(prime);
	return (0);
}

int	ft_release_events(int key, t_prime *prime)
{
	if (key == KEY_W || key == KEY_S)
		prime->fb_status = 0;
	if (key == KEY_A || key == KEY_D)
		prime->rl_status = 0;
	if (key == KEY_RIGHT_ARROW || key == KEY_LEFT_ARROW)
		prime->rotate_status = 0;
	return (0);
}

int	ft_close_botton(t_prime *prime)
{
	ft_clean_exit(prime);
	return (0);
}
