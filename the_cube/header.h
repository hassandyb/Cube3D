/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:18:11 by hed-dyb           #+#    #+#             */
/*   Updated: 2024/01/02 15:02:52 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

# include "parcing/parcing.h"
# include <stdio.h>
# include <stdbool.h>
# include <math.h>
# include <mlx.h>

# define IMG_SIZE 32
# define ROTATE_ANGLE (M_PI / 8)
# define MOVE_DESTANCE 10

# define KEY_W 13
# define KEY_S 1
# define KEY_D 2
# define KEY_A 0
# define KEY_RIGHT_ARROW 124
# define KEY_LEFT_ARROW 123

# define KEY_PRESS 2
# define KEY_RELEASE 3

# define SCREEN_LEN 1280
# define SCREEN_WID 720

typedef struct s_player
{
	double py;
	double px;
	double angle;


}t_player;

// typedef struct s_ray
// {
// 	// general
// 	bool hit;//hits on line == true , hits on rol == false
// 	double r_angle;// the angle of each single ray
// 	double hx;// the point where the player hits
// 	double hy;
// 	double len;
	
// 	// for updats
// 	double deltax;
// 	double deltay;
// 	double first;
// 	double periodic;
	
// 	//  case line
// 	double l_len;
	
// 	//case col
// 	double c_len;

	
	
// } t_ray;


typedef struct s_prime
{
	t_parse *parse;
	unsigned int lines;
	unsigned int cols;
	t_player player;
	void	*mlx_ptr;
	void	*win_ptr;

	
	int fb_status;
	int rl_status;
	int rotate_status;

	int angle_range;// 1 or 2 or 3 or 4

	t_ray ray;
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



void ft_intersection(t_prime *prime, double r_angle);


#endif