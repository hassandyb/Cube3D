/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:18:11 by hed-dyb           #+#    #+#             */
/*   Updated: 2024/01/10 12:08:14 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

# include "parcing/parcing.h"
# include <stdio.h>
# include <stdbool.h>
# include <math.h>
# include <mlx.h>
# include <unistd.h>// remove later

# define IMG_SIZE 32
# define ROTATE_ANGLE (M_PI / 49)
# define MOVE_DESTANCE 7

# define KEY_W 13
# define KEY_S 1
# define KEY_D 2
# define KEY_A 0
# define KEY_RIGHT_ARROW 124
# define KEY_LEFT_ARROW 123
# define KEY_ESC 53
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define DESTROYNOTIFY 17

# define SCREEN_WID 1080
# define SCREEN_HEI 720
# define FIELD_OF_VIEW (M_PI / 3)


typedef struct s_player
{
	double py;
	double px;
	double angle;


}t_player;

typedef struct s_ray
{
	// general
	double len;// the lenth between the player and the wall 
	int hit;// 
	//1 == hit the east wall
	// 2 == hits the south wall
	// 3 == hits the west wall
	// 4 == hits 
	double r_angle;// the angle of each single ray
	

	// for updats
	double deltax;
	double deltay;
	double first;
	double periodic;
	
	//  lenth case line
	double l_len;
	
	//lenth case colloms
	double c_len;

	
	
} t_ray;

typedef struct s_wall 
{
	double d;// fixed destance
	int h;// lenth on the screen - number of pixels wall


}t_wall;


typedef struct s_prime
{
	t_parse *parse;
	unsigned int lines;
	unsigned int cols;
	t_player player;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char		*ad_ptr;

	int bits;// number ofbits in each pixel
	int linesize; //number of pixelsin each line...

	
	int fb_status;
	int rl_status;
	int rotate_status;

	int angle_range;// 1 or 2 or 3 or 4
	

	t_ray ray;
	t_wall wall;
} t_prime;




// main functions
void ft_initialize(t_prime *prime, t_parse *parse);
bool ft_rendering(t_prime *prime);

int ft_press_events(int key, t_prime *prime);
void ft_update_range(t_prime *prime);
int ft_release_events(int key, t_prime *prime);
int ft_raycast_and_render(t_prime *prime);
void ft_update_postion(t_prime *prime);
void ft_full_cords_if_possible(t_prime *prime, double tox, double toy);
int ft_press_events(int key, t_prime *prime);
int ft_release_events(int key, t_prime *prime);
void ft_first_range(t_prime *prime);
void ft_second_range(t_prime *prime);
void ft_third_range(t_prime *prime);
void ft_fourth_range(t_prime *prime);
bool ft_wall_collision_case(t_prime *prime,  int i, int j);
void ft_update_range(t_prime *prime);
void ft_update_angle(t_prime *prime);
void ft_update_postion(t_prime *prime);
bool ft_valid_i(t_prime *prime, double pt_x);
bool ft_valid_j(t_prime *prime, double pt_y);
bool ft_is_intersection_point(t_prime *prime, double pt_x, double pt_y);
void ft_final_update(t_prime *prime);
void ft_update_hit_r1(t_prime *prime);
void ft_special_case_r1(t_prime *prime);
void ft_update_line_r1(t_prime *prime);
void ft_find_l_len_r1(t_prime *prime);
void ft_update_col_r1(t_prime *prime);
void ft_find_c_len_r1(t_prime *prime);
void  ft_raycast_r1(t_prime *prime);
void ft_update_hit_r2(t_prime *prime);
void ft_special_case_r2(t_prime *prime);
void ft_ft_update_line_r2(t_prime *prime);
void ft_find_l_len_r2(t_prime *prime);
void ft_update_col_r2(t_prime *prime);
void ft_find_c_len_r2(t_prime *prime);
void ft_raycast_r2(t_prime *prime);
void ft_update_hit_r3(t_prime *prime);
void ft_special_case_r3(t_prime *prime);
void ft_update_line_r3(t_prime *prime);
void ft_find_l_len_r3(t_prime *prime);
void ft_update_col_r3(t_prime *prime);
void ft_find_c_len_r3(t_prime *prime);
void ft_raycast_r3(t_prime *prime);
void ft_update_hit_r4(t_prime *prime);
void ft_special_case_r4(t_prime *prime);
void 	ft_update_line_r4(t_prime *prime);
void ft_find_l_len_r4(t_prime *prime);
void ft_update_col_r4(t_prime *prime);
void ft_find_c_len_r4(t_prime *prime);
void ft_raycast_r4(t_prime *prime);
double ft_normalizing(double angle);
void	ft_cleen_exit(t_prime *prime);
int ft_close_botton(t_prime *prime);


void ft_ray_cast(t_prime *prime);

// remove later
void ft_put_player(t_prime *prime, void *win_ptr);
void ft_color_walls(t_prime *prime);
void ft_draw_line(t_prime *prime, int x1, int y1, double angle, int length, int color);

#endif