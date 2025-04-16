/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:03:31 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/16 13:41:14 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_rt(t_rt *rt)
{
	if (!rt)
		return ;
	if (rt->win)
		mlx_destroy_window(rt->mlx, rt->win);
	if (rt->mlx)
		mlx_destroy_display(rt->mlx);
	if (rt->camera)
		free_camera(rt->camera);
	if (rt->ambient)
		free_ambient(rt->ambient);
	if (rt->light)
		free_light(rt->light);
	if (rt->object)
		free_object(rt->object);
	free(rt);
	rt = NULL;
}

void	free_camera(t_camera *camera)
{
	free(camera);
	camera = NULL;
}

void	free_ambient(t_ambient *ambient)
{
	free(ambient);
	ambient = NULL;
}

void	free_light(t_light *light)
{
	free(light);
	light = NULL;
}

void	free_object(t_object *object)
{
	free(object);
	object = NULL;
}

void	free_vector(t_vector *vector)
{
	free(vector);
	vector = NULL;
}

void	free_color(t_color *color)
{
	free(color);
	color = NULL;
}

void	free_split(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	split = NULL;
}
