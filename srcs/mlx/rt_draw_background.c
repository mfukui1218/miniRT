/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_draw_background.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 06:14:26 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/20 06:14:26 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	rt_draw_background(t_rt *rt)
{
	int		x;
	int		y;

	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			rt_mlx_pixel_put(rt->screen, x, y, BG_COLOR);
			x++;
		}
		y++;
	}
	return (true);
}
