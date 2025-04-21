/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:00:34 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/21 19:33:18 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_rt(t_rt *rt)
{
	rt->mlx = NULL;
	rt->win = NULL;
	rt->rt = NULL;
	rt->screen_image = NULL;
	rt->ambient = NULL;
	rt->camera = NULL;
	rt->light = NULL;
	rt->object = NULL;
	rt->screen.width = 0;
	rt->screen.height = 0;
	rt->screen.aspect_ratio = 0;
	rt->screen.scale = 0;
}
