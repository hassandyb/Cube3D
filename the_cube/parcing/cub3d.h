/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:42:51 by cgouiame          #+#    #+#             */
/*   Updated: 2024/01/20 16:23:52 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_parse
{
	char	**map;
	int		flag;
	int		mapsize;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f;
	int		c;
	double	px;
	double	py;
	char	p;

}	t_parse;



typedef struct s_var
{
	int	i;
	int	j;
	int	k;
}	t_var;

void	ft_parse(int ac, char **av, t_parse *parse);
char	*get_next_line(int fd);
char	*ft_strdup(char *s1);
int		ft_strlen(char *str);
int		is_empty(char *str);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char *p, char *buffer);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_strchr(char *str, char c);
int		getsize(int fd);
void	ft_error(char *str);
void	ft_free_mem(char **tab);
int		my_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_parse_cub(int fd, t_parse *parse, char *av);
char	*ft_erase(char *str);
int		parsemycolor(char *str, t_parse *parse, int flag);
char	**read_map(int fd, char *av, t_parse *parse);
int		parsetexture(char *str, t_parse *parse);
char	*skip_space(char *str);
#endif