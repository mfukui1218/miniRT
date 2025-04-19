/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_print_rt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:10:43 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/19 22:15:03 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "miniRT.h"

void	rt_print_rt(const t_rt *rt)
{
	if (rt == NULL)
		return ;
	printf("{\n");
	printf("	mlx: %p\n", rt->mlx);
	printf("	win: %p\n", rt->win);
	printf("	rt: ");
	rt_print_ntp((const void **)rt->rt, (void (*)(const void *))rt_print_str);
	printf("\n");
	printf("	camera: ");
	rt_print_camera(rt->camera);
	printf("	ambient: ");
	rt_print_ambient(rt->ambient);
	printf("	light: ");
	rt_print_light(rt->light);
	printf("	object: ");
	rt_print_list(rt->object, (void (*)(const void *))rt_print_object);
	printf("}\n");
}

/**
 * typedef struct s_object
{
t_obj_type type;
void *object;
t_color color;
} t_object;

typedef struct s_sphere
{
t_vector position;
float radius;
} t_sphere;

typedef struct s_plane
{
t_vector position;
t_vector orientation;
} t_plane;

typedef struct s_cylinder
{
t_vector position;
t_vector orientation;
float radius;
float height;
} t_cylinder;
 */
