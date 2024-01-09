/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:23:06 by hed-dyb           #+#    #+#             */
/*   Updated: 2024/01/09 10:22:34 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

// Useful ##########################################



void ft_put_a_pixel(t_prime *prime, int x, int y, int color)
{
    int pos =  (y * prime->linesize + x * (prime->bits / 8));// divded on 8 tio transform it to byte

    // x * (prime->bits / 8) the pexel is color  we want is stoes as int, but we incrent in
    //  byts (so multiple the buy 4 wich is (prime->bits / 8) to each 
    // the begining of the int we are about to chage

    *(unsigned int *)(prime->ad_ptr + pos) = color;
}

void ft_put_player(t_prime *prime, void *win_ptr)
{
    (void)win_ptr;
    ft_put_a_pixel(prime, prime->player.px, prime->player.py, 0xFF0000);
	ft_put_a_pixel(prime, prime->player.px -1, prime->player.py, 0xFF0000);
	ft_put_a_pixel(prime, prime->player.px + 1, prime->player.py, 0xFF0000);

	ft_put_a_pixel(prime, prime->player.px, prime->player.py + 1, 0xFF0000);
	ft_put_a_pixel(prime, prime->player.px, prime->player.py - 1, 0xFF0000);

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
                for (int i = 0; i < square_size; i++)
                {
                    for (int j = 0; j < square_size; j++)
                    {
                        ft_put_a_pixel(prime, (x * square_size) + i, (y * square_size) + j, color);
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
        ft_put_a_pixel(prime, x, y, color);

    }
}
// -----------------------------------------------------------------

void  ft_show_field_of_view(t_prime *prime)
{
    double teta;
    int i ;


    teta = FIELD_OF_VIEW / SCREEN_WID;
    prime->ray.r_angle = prime->player.angle - (FIELD_OF_VIEW / 2);
    prime->ray.r_angle = ft_normalizing(prime->ray.r_angle);
    i = 0;
    while(i < SCREEN_WID)
    {
        ft_ray_cast(prime);
        ft_draw_line(prime, prime->player.px, prime->player.py, prime->ray.r_angle, prime->ray.len, 0x6496C8);
        prime->ray.r_angle += teta;
        prime->ray.r_angle = ft_normalizing(prime->ray.r_angle);
        i++;
    }
    
}

// -----------------------------------------------------------------------------



bool ft_init_mlx_data(t_prime *prime)
{
    int parameter;
    prime->mlx_ptr = mlx_init();
    if(prime->mlx_ptr == NULL)
		return false;
    prime->win_ptr = mlx_new_window(prime->mlx_ptr, prime->cols * IMG_SIZE, prime->lines * IMG_SIZE, "my window");
    if(prime->win_ptr == NULL)
        return false;
    prime->img_ptr = mlx_new_image(prime->mlx_ptr, SCREEN_WID, SCREEN_HEI);
    if(prime->img_ptr == NULL)
        return false;
    // 0 0 are the begining of i and j wree yu wanna start to put the image
    prime->ad_ptr = mlx_get_data_addr(prime->img_ptr, &prime->bits, &prime->linesize , &parameter);
    if(prime->ad_ptr == NULL)
        return false;
    
    return true;
}

int ft_raycast_and_render(t_prime *prime)
{
    int parameter;
	ft_update_range(prime);
	ft_update_postion(prime);
	ft_update_angle(prime);
	
	// to remove later ####################################
    mlx_destroy_image(prime->mlx_ptr, prime->img_ptr);
    prime->img_ptr = mlx_new_image(prime->mlx_ptr, SCREEN_WID, SCREEN_HEI);
    prime->ad_ptr = mlx_get_data_addr(prime->img_ptr, &prime->bits, &prime->linesize , &parameter);
    

    ft_color_walls((prime));
	ft_put_player(prime, prime->win_ptr);
	ft_show_field_of_view(prime);
    

    mlx_put_image_to_window(prime->mlx_ptr, prime->win_ptr,prime->img_ptr, 0, 0);

	return 0;
}


bool ft_rendering(t_prime *prime)
{
	
	
	if(ft_init_mlx_data(prime) == false)
    {
        // ft_cleen_exit(t_prime *prime);
    }


	mlx_hook(prime->win_ptr, KEY_PRESS, 0L, ft_press_events, prime);
	mlx_hook(prime->win_ptr, KEY_RELEASE, 0L, ft_release_events, prime);
    mlx_hook(prime->win_ptr, DESTROYNOTIFY, 0L, ft_close_botton, prime);
	mlx_loop_hook(prime->mlx_ptr, ft_raycast_and_render, prime);


	mlx_loop(prime->mlx_ptr);
	return true;
}






























