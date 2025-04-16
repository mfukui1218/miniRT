/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:00:34 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/16 13:33:14 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_rt(t_rt *rt)
{
	rt->mlx = NULL;
	rt->win = NULL;
	rt->rt = NULL;
	rt->ambient = NULL;
	rt->camera = NULL;
	rt->light = NULL;
	rt->object = NULL;
}

void	init_ambient(t_ambient *ambient)
{
	ambient->brightness = 0;
	ambient->color = (t_color){0, 0, 0};
}

void	init_camera(t_camera *camera)
{
	camera->position = (t_vector){0, 0, 0};
	camera->orientation = (t_vector){0, 0, -1};
	camera->fov = 0;
}

void	init_light(t_light *light)
{
	light->position = (t_vector){0, 0, 0};
	light->brightness = 0;
	light->color = (t_color){255, 255, 255};
}

void	init_object(t_object *object)
{
	object->type = 0;
	object->position = (t_vector){0, 0, 0};
	object->orientation = (t_vector){0, 0, 0};
	object->color = (t_color){255, 255, 255};
	object->radius = 0;
	object->height = 0;
}

void	init_vector(t_vector *vector)
{
	vector->x = 0;
	vector->y = 0;
	vector->z = 0;
}

void	init_color(t_color *color)
{
	color->r = 0;
	color->g = 0;
	color->b = 0;
}
