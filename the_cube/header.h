/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:18:11 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/12/23 20:03:44 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

#include "parcing/parcing.h"
#include <stdio.h>
#include <stdbool.h>


typedef struct s_prime
{
	t_parse *parse;
	unsigned int width;
	unsigned int heith;


} t_prime;

// main functions
bool ft_do_ray_casting(t_prime *prime, t_parse *parse);
#endif