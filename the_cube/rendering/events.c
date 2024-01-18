/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:42:38 by hed-dyb           #+#    #+#             */
/*   Updated: 2024/01/18 16:07:23 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_clean_exit(t_prime *prime)
{
	int j;

	j = -1;
	while(prime->parse->map[++j] != NULL)
	{
		free(prime->parse->map[j]);
	}
	free(prime->parse->map);
	free(prime->parse);
	// free any other dataallocated
		// if(ptr .. != NULL)
		// mlx_destroy_image  w
		//  mlx_destroy_image  n
		//  mlx_destroy_image  s
		//   mlx_destroy_image  east 

	if(prime->mlx_ptr != NULL && prime->img_ptr != NULL)
		mlx_destroy_image(prime->mlx_ptr, prime->img_ptr);

	// if(wi_ptr != NULL)
		// mlx_clear_window 
	//if(mlx_ptr != NULL)
		// mlx_destroy_window
	printf("Successful exit.\n");
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
