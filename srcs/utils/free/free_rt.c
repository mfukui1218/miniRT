/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:03:31 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/19 18:36:08 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_rt(t_rt *rt)
{
	if (!rt)
		return ;
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
