/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:23:06 by hed-dyb           #+#    #+#             */
/*   Updated: 2024/01/15 15:47:04 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

// 2D ##########################################

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
//-----------------------------------------------------------------------

bool ft_load_img(t_prime *prime, char *path, int car)// car refes to cardinal wish is east west south ..ext
{
	int width;
	int height;
	int bits_per_pixel;
	int size_line;
	int endian;

	prime->imgs[car].obj = mlx_xpm_file_to_image(prime->mlx_ptr, path, &width, &height);
	if(prime->imgs[car].obj == NULL)
	{

		return false;
	}
		
	
	prime->imgs[car].wid = width;
	prime->imgs[car].hei = height;
	
	prime->imgs[car].ad = mlx_get_data_addr(prime->imgs[car].obj, &bits_per_pixel, &size_line, &endian);
	if(prime->imgs[car].ad == NULL)
		return false;
	prime->imgs[car].size_line = size_line;
	prime->imgs[car].bits_per_pixel = bits_per_pixel;
	return true;
}

bool ft_load_textures(t_prime *prime)
{
	if(ft_load_img(prime, prime->parse->ea, EAST) == false)
		return false;

	
	
	if(ft_load_img(prime, prime->parse->so, SOUTH) == false)
		return false;


	if(ft_load_img(prime, prime->parse->we, WEST) == false)
		return false;

	if(ft_load_img(prime, prime->parse->no, NORTH) == false)
		return false;
	return true;

}

bool ft_init_mlx_data(t_prime *prime)
{
	int parameter;
	prime->mlx_ptr = mlx_init();
	if(prime->mlx_ptr == NULL)
		return false;
	prime->win_ptr = mlx_new_window(prime->mlx_ptr, SCREEN_WID , SCREEN_HEI, "my window");
	if(prime->win_ptr == NULL)
		return false;
	prime->img_ptr = mlx_new_image(prime->mlx_ptr, SCREEN_WID , SCREEN_HEI);
	if(prime->img_ptr == NULL)
		return false;
	// 0 0 are the begining of i and j wree yu wanna start to put the image
	prime->ad_ptr = mlx_get_data_addr(prime->img_ptr, &prime->bits, &prime->linesize , &parameter);
	if(prime->ad_ptr == NULL)
		return false;
	
	
	

	if(ft_load_textures(prime) == false)
		return false;
	
	return true;
}

// -----------------------------------------------------------------------------

void ft_sky_and_ground(t_prime *prime)
{
	int half;
	int i;
	int j;

	i = -1;
	j = -1;
	half = SCREEN_HEI / 2;
	while(++j < half)
	{
		i = -1;
		while(++i < SCREEN_WID)
			// ft_put_a_pixel(prime, i, j, 0x000000);
			ft_put_a_pixel(prime, i, j, 0x012840);
	}
	j--;
	while(++j < SCREEN_HEI)
	{
		i = -1;
		while(++i < SCREEN_WID)
			ft_put_a_pixel(prime, i, j, 0x011826);
	}

}


//###########################################################


void ft_show_the_colom_v1(t_prime *prime, int x, int color)// used to color walls only
{
	int y;
	int count;


	count = 0;
	y =(( SCREEN_HEI - prime->wall.h ) / 2) - 1;
	if(y < 0)
		y = 0;
	while(count < prime->wall.h)
	{
		if(y >= SCREEN_HEI)
			return ;
		ft_put_a_pixel(prime, x, y, color);
		y++;
		count++;
		

	}
}

//#######################################################################


bool ft_the_easy_cases(t_prime *prime)
{
	if(prime->ray.r_angle == 0 || prime->ray.r_angle == M_PI)
	{
		prime->wall.x_tile = (int)prime->player.py % IMG_SIZE;

		return true;
	}
	if(prime->ray.r_angle == (M_PI / 2) || prime->ray.r_angle == (3 * M_PI / 2))
	{
		prime->wall.x_tile = (int)prime->player.px % IMG_SIZE;
		return true;
	}
	return false;
}

long ft_l_on_r1(t_prime *prime)
{
	double alpha;
	long l;

	alpha = prime->ray.r_angle;
	if(prime->ray.hit == 1)// hits a a col == 
		l = prime->player.py + (prime->ray.len * sin(alpha));
	else
		l = prime->player.px  + (prime->ray.r_angle * cos(alpha));
	return l;
}

long ft_l_on_r2(t_prime *prime)
{
	double alpha;
	long l;
	
	alpha = prime->ray.r_angle - (M_PI / 2);
	if(prime->ray.hit == 2) // hits a the line south
		l = prime->player.px - (prime->ray.len * sin(alpha));
	else
		l = prime->player.py + (prime->ray.len * cos(alpha));
	return l;
}

long ft_l_on_r3(t_prime *prime)
{
	double alpha;
	long l;
	
	alpha = prime->ray.r_angle - M_PI;
	if(prime->ray.hit == 3)// hit the col == weats wall
		l = prime->player.py - (prime->ray.len * sin (alpha));
	else
		l = prime->player.px - (prime->ray.len * cos(alpha));
	return l;
}

long ft_l_on_r4(t_prime *prime)
{
	double alpha;
	long l;
	
	alpha = prime->ray.r_angle - (3 * M_PI / 2);
	if (prime->ray.hit == 4)// his the line == north
		l = prime->player.px + (prime->ray.len * sin(alpha));
	else
		l = prime->player.py - (prime->ray.len * cos (alpha));
	return l;
	
}

void ft_find_x_tile(t_prime *prime)
{
	long l ;// is conds pt_ x if it hits a line or pt_y if hits a col of the intersection point.
	if(ft_the_easy_cases(prime) == true)
		return;
	if(prime->ray.r_angle > 0 && prime->ray.r_angle < (M_PI / 2))
		l = ft_l_on_r1(prime);
	else if (prime->ray.r_angle > (M_PI / 2) && prime->ray.r_angle < M_PI)
		l = ft_l_on_r2(prime);
	else if(prime->ray.r_angle > M_PI && prime->ray.r_angle < (3 * M_PI / 2))
		l = ft_l_on_r3(prime);
	else
		l = ft_l_on_r3(prime);
	prime->wall.x_tile = l % IMG_SIZE;
	

}
// -------------------------------------

t_img ft_which_texture(t_prime *prime)
{
	t_img img;

	if(prime->ray.hit == HIT_EAST)
		img = prime->imgs[EAST];
	if(prime->ray.hit == HIT_SOUTH)
		img = prime->imgs[SOUTH];
	if(prime->ray.hit == HIT_WEST)
		img = prime->imgs[WEST];
	if(prime->ray.hit == HIT_NORTH)
		img = prime->imgs[NORTH];
	return img;
}

unsigned int ft_which_color(t_prime *prime, t_img img, int count)
{
	
	int x_img;
	int y_img;
	long pos;
	unsigned int color;
	
	x_img = ((img.wid - 1) * prime->wall.x_tile) / (IMG_SIZE - 1);
	y_img = ((img.hei - 1) * count) / (prime->wall.h - 1);
	
	pos = ((y_img * img.size_line) + (x_img * img.bits_per_pixel / 8));
	
	color = (*(unsigned int *)(img.ad + pos));
	return (color);
}

void ft_show_the_colom(t_prime *prime, double x_screen)// on prosses
{
	int y_screen;
	t_img img;// with texture
	int count;
	unsigned int color;

	y_screen = (( SCREEN_HEI - prime->wall.h ) / 2) - 1;
	count = 0;
	
	img = ft_which_texture(prime);
	
	if(y_screen < 0)
		y_screen = 0;
	while(count < prime->wall.h)
	{
		if(y_screen >= SCREEN_HEI)
			return ;
		color = ft_which_color(prime, img, count);

		// printf("%d-%d     %d   %d\n", img.wid, img.hei, x_screen, y_screen);
		ft_put_a_pixel(prime, x_screen, y_screen, color);
		y_screen++;
		count ++;
	}
	


}

void ft_length_on_screen(t_prime *prime)
{
	prime->wall.real = prime->ray.len * cos(prime->ray.r_angle - prime->player.angle);
		prime->wall.h = (IMG_SIZE * prime->wall.d) / prime->wall.real;
}


void ft_show_3d_walls(t_prime *prime)
{
	double teta;
	int x_screen ;



	teta = FIELD_OF_VIEW / SCREEN_WID;
	prime->ray.r_angle = prime->player.angle - (FIELD_OF_VIEW / 2);
	prime->ray.r_angle = ft_normalizing(prime->ray.r_angle);
	x_screen = 0;
	while(x_screen < SCREEN_WID)
	{
		ft_ray_cast(prime);
		ft_length_on_screen(prime);// to find prime->wall.h the number pixls for this color on the screen and remove fich eye
		ft_find_x_tile(prime);// to find out prime->wall.x_tile     the with pixels is actually hited on eather line/colom on my tail side 32
		

		
		ft_show_the_colom(prime,x_screen);



		// ft_show_the_colom_v1(prime, x_screen, 0x8B0000);// used for coloring walls only

		
		prime->ray.r_angle += teta;
		prime->ray.r_angle = ft_normalizing(prime->ray.r_angle);
		x_screen++;
	}
	
}

int ft_raycast_and_render(t_prime *prime)
{
	int parameter;
	ft_update_range(prime);
	ft_update_postion(prime);
	ft_update_angle(prime);
	
	//####################################
	mlx_destroy_image(prime->mlx_ptr, prime->img_ptr);
	prime->img_ptr = mlx_new_image(prime->mlx_ptr, SCREEN_WID, SCREEN_HEI);
	prime->ad_ptr = mlx_get_data_addr(prime->img_ptr, &prime->bits, &prime->linesize , &parameter);
	
	ft_sky_and_ground(prime);
	
	ft_show_3d_walls(prime);

	
	

	// ft_color_walls((prime));
	// ft_put_player(prime, prime->win_ptr);
	// ft_show_field_of_view(prime);
	

	mlx_put_image_to_window(prime->mlx_ptr, prime->win_ptr,prime->img_ptr, 0, 0);

	return 0;
}

bool ft_rendering(t_prime *prime)
{
	
	
	if(ft_init_mlx_data(prime) == false)
	{
		printf("faled to initialize the data.\n");// remove later
		// ft_cleen_exit(t_prime *prime);
		exit(0);// remove later
	}


	mlx_hook(prime->win_ptr, KEY_PRESS, 0L, ft_press_events, prime);
	mlx_hook(prime->win_ptr, KEY_RELEASE, 0L, ft_release_events, prime);
	mlx_hook(prime->win_ptr, DESTROYNOTIFY, 0L, ft_close_botton, prime);
	mlx_loop_hook(prime->mlx_ptr, ft_raycast_and_render, prime);
	mlx_loop(prime->mlx_ptr);
	return true;
}






























