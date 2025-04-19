/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:00:34 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/19 18:29:55 by mfukui           ###   ########.fr       */
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
