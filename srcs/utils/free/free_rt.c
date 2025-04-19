/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:03:31 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/20 06:46:19 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_rt(t_rt *rt)
{
	if (!rt)
		return ;
	if (rt->screen)
	{
		rt_destroy_image(rt->mlx, rt->screen);
		rt->screen = NULL;
	}
	if (rt->win)
	{
		mlx_destroy_window(rt->mlx, rt->win);
		rt->win = NULL;
	}
	if (rt->mlx)
	{
		mlx_destroy_display(rt->mlx);
		free(rt->mlx);
		rt->mlx = NULL;
	}
	if (rt->rt)
		free_txt(rt->rt);
	if (rt->camera)
		free_camera(rt->camera);
	if (rt->ambient)
		free_ambient(rt->ambient);
	if (rt->light)
		free_light(rt->light);
	if (rt->object)
		free_object_list(&rt->object);
	free(rt);
	rt = NULL;
}
