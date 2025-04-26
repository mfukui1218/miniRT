/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_key_event_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 04:20:45 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/20 04:20:45 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <X11/Xutil.h>

int	rt_key_event_handler(int keycode, t_rt *rt)
{
	if (keycode == XK_Escape)
	{
		free_rt(rt);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

// for debug key event
// int	rt_key_event_handler(int keycode, t_rt *rt)
// {
// 	bool	redraw;

// 	redraw = false;
// 	if (keycode == XK_Escape)
// 	{
// 		free_rt(rt);
// 		exit(EXIT_SUCCESS);
// 	}
// 	if (keycode == XK_d)
// 	{
// 		rt->camera->position.x += 1;
// 		redraw = true;
// 	}
// 	else if (keycode == XK_a)
// 	{
// 		rt->camera->position.x -= 1;
// 		redraw = true;
// 	}
// 	else if (keycode == XK_w)
// 	{
// 		rt->camera->position.z += 1;
// 		redraw = true;
// 	}
// 	else if (keycode == XK_s)
// 	{
// 		rt->camera->position.z -= 1;
// 		redraw = true;
// 	}
// 	else if (keycode == XK_q)
// 	{
// 		rt->camera->position.y -= 1;
// 		redraw = true;
// 	}
// 	else if (keycode == XK_e)
// 	{
// 		rt->camera->position.y += 1;
// 		redraw = true;
// 	}
// 	else if (keycode == XK_j)
// 	{
// 		rt->camera->orientation.x -= 0.1;
// 		if (rt->camera->orientation.x < -1)
// 			rt->camera->orientation.x = -1;
// 		redraw = true;
// 	}
// 	else if (keycode == XK_l)
// 	{
// 		rt->camera->orientation.x += 0.1;
// 		if (rt->camera->orientation.x > 1)
// 			rt->camera->orientation.x = 1;
// 		redraw = true;
// 	}
// 	else if (keycode == XK_i)
// 	{
// 		rt->camera->orientation.y -= 0.1;
// 		if (rt->camera->orientation.y < -1)
// 			rt->camera->orientation.y = -1;
// 		redraw = true;
// 	}
// 	else if (keycode == XK_k)
// 	{
// 		rt->camera->orientation.y += 0.1;
// 		if (rt->camera->orientation.y > 1)
// 			rt->camera->orientation.y = 1;
// 		redraw = true;
// 	}
// 	else if (keycode == XK_u)
// 	{
// 		rt->camera->orientation.z -= 0.1;
// 		if (rt->camera->orientation.z < -1)
// 			rt->camera->orientation.z = -1;
// 		redraw = true;
// 	}
// 	else if (keycode == XK_o)
// 	{
// 		rt->camera->orientation.z += 0.1;
// 		if (rt->camera->orientation.z > 1)
// 			rt->camera->orientation.z = 1;
// 		redraw = true;
// 	}
// 	if (redraw)
// 	{
// 		draw(rt);
// 		render(rt);
// 	}
// 	return (0);
// }
