/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 06:48:34 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/20 06:48:34 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	render(t_rt *rt)
{
	mlx_put_image_to_window(rt->mlx, rt->win, rt->screen_image->img, 0, 0);
}
