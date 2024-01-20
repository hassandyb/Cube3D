/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:18:11 by hed-dyb           #+#    #+#             */
/*   Updated: 2024/01/20 15:20:35 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "parcing/cub3d.h"
# include <mlx.h>
# include <stdio.h>
# include <stdbool.h>
# include <math.h>
# include <unistd.h>
# include <string.h>

# define IMG_SIZE 32
# define ROTATE_ANGLE 0.064
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
# define FIELD_OF_VIEW 1.0466666667
# define EAST 0
# define SOUTH 1
# define WEST 2
# define NORTH 3
# define HIT_EAST 1
# define HIT_SOUTH 2
# define HIT_WEST 3
# define HIT_NORTH 4
# define MINI_TILE 20
# define MINI_WID 260
# define MINI_HEI 180
# define MINI_COLS 13
# define MINI_LINES 9
# define RANGE_ONE 1
# define RANGE_TWO 2
# define RANGE_THREE 3
# define RANGE_FOUR 4


typedef struct s_player
{
	double	py;
	double	px;
	double	angle;
}	t_player;

typedef struct s_ray
{
	double	len;
	int		hit;
	double	r_angle;
	double	deltax;
	double	deltay;
	double	first;
	double	periodic;
	double	l_len;
	double	c_len;
}	t_ray;

typedef struct s_wall
{
	double	d;
	int		h;
	double	real;
	int		x_tile;
}	t_wall;

typedef struct s_img
{
	void	*obj;
	char	*ad;
	int		wid;
	int		hei;
	int		size_line;
	int		bits_per_pixel;
}	t_img;

typedef struct s_prime
{
	t_parse			*parse;
	unsigned int	lines;
	unsigned int	cols;
	t_player		player;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*ad_ptr;
	int				bits;
	int				linesize;
	int				fb_status;
	int				rl_status;
	int				rotate_status;
	int				angle_range;
	t_ray			ray;
	t_wall			wall;
	t_img			imgs[4];

}	t_prime;

void			ft_initialize(t_prime *prime, t_parse *parse);
void			ft_rendering(t_prime *prime);
int				ft_press_events(int key, t_prime *prime);
void			ft_update_range(t_prime *prime);
int				ft_release_events(int key, t_prime *prime);
int				ft_raycast_and_render(t_prime *prime);
void			ft_update_postion(t_prime *prime);
void			ft_full_cords_if_possible(t_prime *prime, \
	double tox, double toy);
int				ft_press_events(int key, t_prime *prime);
int				ft_release_events(int key, t_prime *prime);
void			ft_first_range(t_prime *prime);
void			ft_second_range(t_prime *prime);
void			ft_third_range(t_prime *prime);
void			ft_fourth_range(t_prime *prime);
bool			ft_wall_collision_case(t_prime *prime, int i, int j);
void			ft_update_range(t_prime *prime);
void			ft_update_angle(t_prime *prime);
void			ft_update_postion(t_prime *prime);
bool			ft_valid_i(t_prime *prime, double pt_x);
bool			ft_valid_j(t_prime *prime, double pt_y);
bool			ft_is_intersection_point(t_prime *prime, \
	double pt_x, double pt_y);
void			ft_final_update(t_prime *prime);
void			ft_update_hit_r1(t_prime *prime);
void			ft_special_case_r1(t_prime *prime);
void			ft_update_line_r1(t_prime *prime);
void			ft_find_l_len_r1(t_prime *prime);
void			ft_update_col_r1(t_prime *prime);
void			ft_find_c_len_r1(t_prime *prime);
void			ft_raycast_r1(t_prime *prime);
void			ft_update_hit_r2(t_prime *prime);
void			ft_special_case_r2(t_prime *prime);
void			ft_ft_update_line_r2(t_prime *prime);
void			ft_find_l_len_r2(t_prime *prime);
void			ft_update_col_r2(t_prime *prime);
void			ft_find_c_len_r2(t_prime *prime);
void			ft_raycast_r2(t_prime *prime);
void			ft_update_hit_r3(t_prime *prime);
void			ft_special_case_r3(t_prime *prime);
void			ft_update_line_r3(t_prime *prime);
void			ft_find_l_len_r3(t_prime *prime);
void			ft_update_col_r3(t_prime *prime);
void			ft_find_c_len_r3(t_prime *prime);
void			ft_raycast_r3(t_prime *prime);
void			ft_update_hit_r4(t_prime *prime);
void			ft_special_case_r4(t_prime *prime);
void			ft_update_line_r4(t_prime *prime);
void			ft_find_l_len_r4(t_prime *prime);
void			ft_update_col_r4(t_prime *prime);
void			ft_find_c_len_r4(t_prime *prime);
void			ft_raycast_r4(t_prime *prime);
double			ft_normalizing(double angle);
void			ft_cleen_exit(t_prime *prime);
int				ft_close_botton(t_prime *prime);
void			ft_clean_exit(t_prime *prime);
void			ft_ray_cast(t_prime *prime);
void			ft_mini_map_background(t_prime *prime);
void			ft_draw_mini_tile(t_prime *prime, int i_mini, int j_mini);
void			ft_first_tile_cord(t_prime *prime, int *i_map, int *j_map);
bool			ft_valid_drawing(t_prime *prime, int i_map, int j_map);
void			ft_mini_map_walls(t_prime *prime);
void			ft_mini_player_dir(t_prime *prime, int px, int py);
void			ft_draw_player(t_prime *prime, int dx_mini, int dy_mini);
void			ft_mini_player(t_prime *prime);
void			ft_the_mini_map(t_prime *prime);
void			ft_put_a_pixel(t_prime *prime, int x, int y, int color);
t_img			ft_which_texture(t_prime *prime);
unsigned int	ft_which_color(t_prime *prime, t_img img, int count);
void			ft_show_the_colom(t_prime *prime, double x_screen);
void			ft_length_on_screen(t_prime *prime);
void			ft_show_3d_walls(t_prime *prime);
void			ft_find_x_tile(t_prime *prime);
long			ft_l_on_r4(t_prime *prime);
long			ft_l_on_r3(t_prime *prime);
long			ft_l_on_r2(t_prime *prime);
long			ft_l_on_r1(t_prime *prime);
bool			ft_the_easy_cases(t_prime *prime);
void			ft_put_a_pixel(t_prime *prime, int x, int y, int color);
bool			ft_load_img(t_prime *prime, char *path, int car);
bool			ft_load_textures(t_prime *prime);
bool			ft_init_mlx_data(t_prime *prime);
void			ft_free_mem(char **tab);
#endif