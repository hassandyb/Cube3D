/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:23:06 by hed-dyb           #+#    #+#             */
/*   Updated: 2024/01/02 14:57:15 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

// remove later ##########################################

void ft_put_player(t_prime *prime, void *win_ptr)
{
	mlx_pixel_put(prime->mlx_ptr, win_ptr, prime->player.px, prime->player.py, 0xFF0000);
	mlx_pixel_put(prime->mlx_ptr, win_ptr, prime->player.px -1, prime->player.py, 0xFF0000);
	mlx_pixel_put(prime->mlx_ptr, win_ptr, prime->player.px + 1, prime->player.py, 0xFF0000);

	mlx_pixel_put(prime->mlx_ptr, win_ptr, prime->player.px, prime->player.py + 1, 0xFF0000);
	mlx_pixel_put(prime->mlx_ptr, win_ptr, prime->player.px, prime->player.py - 1, 0xFF0000);
}

void ft_color_walls(t_prime *prime)
{
    int x, y;
    int square_size = 32; // Adjust the size of the square as needed
    int color = 0xA7C957; // Specify the color for '1'

    y = 0;
    while (prime->parse->map[y])
    {
        x = 0;
        while (prime->parse->map[y][x])
        {
            if (prime->parse->map[y][x] == '1')
            {
                // Color the square with the specified color
                for (int i = 0; i < square_size; i++)
                {
                    for (int j = 0; j < square_size; j++)
                    {
                        mlx_pixel_put(prime->mlx_ptr, prime->win_ptr, (x * square_size) + i, (y * square_size) + j, color);
                    }
                }
            }
            x++;
        }
        y++;
    }
}

void ft_draw_line(t_prime *prime, int x1, int y1, double angle, int length, int color)
{
    double dx = cos(angle);
    double dy = sin(angle);

    for (int i = 0; i < length; i++)
    {
        int x = x1 + i * dx;
        int y = y1 + i * dy;
        mlx_pixel_put(prime->mlx_ptr, prime->win_ptr, x, y, color);
    }
}
// ----------------------------------

void ft_update_range(t_prime *prime)
{
	if(prime->player.angle >= 0 && prime->player.angle < (M_PI / 2))
		prime->angle_range = 1;
	if(prime->player.angle >= (M_PI / 2) && prime->player.angle < M_PI)
		prime->angle_range = 2;
	if(prime->player.angle >= M_PI && prime->player.angle < (3 * M_PI / 2))
		prime->angle_range = 3;
	if(prime->player.angle >= (3 * M_PI / 2) && prime->player.angle < (2 * M_PI))
		prime->angle_range = 4;
}

void ft_update_angle(t_prime *prime)
{
	if(prime->rotate_status == 1)
		prime->player.angle += ROTATE_ANGLE;
	if(prime->rotate_status == -1)
		prime->player.angle -= ROTATE_ANGLE;
	// normalizing
	if(prime->player.angle < 0)
		prime->player.angle += (2 * M_PI);
	if(prime->player.angle >= (2 * M_PI))
		prime->player.angle -= (2 * M_PI);

}

void ft_update_postion(t_prime *prime)
{
	if(prime->angle_range == 1 )
	{
		ft_first_range(prime);
	}
	if(prime->angle_range == 2)
	{
		ft_second_range(prime);
	}
	if(prime->angle_range == 3)
	{
		ft_third_range(prime);
	}
	if(prime->angle_range == 4)
	{
		ft_fourth_range(prime);
	}
}


// In process -----------------------------------------------------------------------------------------------------------



void ft_update_line_r1(t_prime *prime)
{
	int j;
	double alpha;

	j = prime->player.py / IMG_SIZE;
	prime->ray.deltay = ((j + 1) * IMG_SIZE) - prime->player.py;
	alpha = prime->ray.r_angle;
	prime->ray.deltax = prime->ray.deltay / tan(alpha);
	prime->ray.first = prime->ray.deltay / sin(alpha);
	prime->ray.periodic = IMG_SIZE / sin(alpha);

}

void ft_find_l_len_r1(t_prime *prime)
{
	int i;
	int j;
	double point_x;
	double point_y;
	double alpha;

	alpha = prime->ray.r_angle;
	point_x = prime->player.px + prime->ray.deltax;
	j = prime->player.py / IMG_SIZE;
	point_y = (j +  1) * IMG_SIZE;
	
	i = point_x / IMG_SIZE;
	j = point_y / IMG_SIZE;
	if(prime->parse->map[j][i] == '1')
		prime->ray.l_len = prime->ray.first;
	else
	{
		while(1)
		{
			point_x += prime->ray.periodic * cos(alpha);
			point_y += IMG_SIZE;
			i = point_x / IMG_SIZE;
			j = point_y / IMG_SIZE;
			prime->ray.l_len += prime->ray.periodic;
			if(prime->parse->map[j][i] == '1')
				break;
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

// void ft_find_c_len_r1(t_prime *prime)
// {
// 	int i;
// 	int j;
// 	double point_x;
// 	double point_y;
// 	double alpha;

// 	alpha = prime->player


	
// }


// void ft_intersection(t_prime *prime, double r_angle)
// {
// 	// you must get the r_angle normalized
// 	// initilise the r_angle with something like playera nagle 
// 	prime->ray.r_angle = r_angle;

// 	if(r_angle >= 0 && r_angle < M_PI / 2)
// 	{
		
// 		ft_update_line_r1(prime);
// 		ft_find_l_len_r1(prime);
// 		ft_update_col_r1(prime);
// 		// ft_find_c_len_r1(prime);
// 		// update step buy step...
// 		// ft_update_hit_and_len(prime);
// 		// return d;

// 	}

// }

//----------------------------------------------------------------


int ft_raycast_and_render(t_prime *prime)
{
	
	ft_update_postion(prime);
	ft_update_angle(prime);
	ft_update_range(prime);
	// to remove later -----
	mlx_clear_window(prime->mlx_ptr ,prime->win_ptr);
	ft_draw_line(prime, prime->player.px, prime->player.py, prime->player.angle, 30, 0x6496C8);
	ft_color_walls((prime));
	ft_put_player(prime, prime->win_ptr);
	

	return 0;
}

bool ft_rendering(t_prime *prime)
{
	prime->mlx_ptr = mlx_init();
	if(prime->mlx_ptr == NULL)
		return false;
	
	prime->win_ptr = mlx_new_window(prime->mlx_ptr, prime->cols * IMG_SIZE, prime->lines * IMG_SIZE, "my window");
	
	// to remove or mofify : ----------------------------------
	ft_draw_line(prime, prime->player.px, prime->player.py, prime->player.angle, 30, 0x6496C8);
	ft_color_walls((prime));
	ft_put_player(prime, prime->win_ptr);
	
	
	mlx_hook(prime->win_ptr, KEY_PRESS, 0L, ft_press_events, prime);
	mlx_hook(prime->win_ptr, KEY_RELEASE, 0L, ft_release_events, prime);
	mlx_loop_hook(prime->mlx_ptr, ft_raycast_and_render, prime);


	mlx_loop(prime->mlx_ptr);
	return true;
}






























