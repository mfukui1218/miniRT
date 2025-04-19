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
