/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:00:34 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/20 06:16:37 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_rt(t_rt *rt)
{
	rt->mlx = NULL;
	rt->win = NULL;
	rt->rt = NULL;
	rt->screen = NULL;
	rt->ambient = NULL;
	rt->camera = NULL;
	rt->light = NULL;
	rt->object = NULL;
}
