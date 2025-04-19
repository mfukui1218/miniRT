/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_print_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:20:21 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/20 01:10:19 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rt_print_camera(const t_camera *camera)
{
	if (camera == NULL)
		return ;
	rt_print_str("position: ");
	rt_print_vector(&camera->position);
	rt_print_str("orientation: ");
	rt_print_vector(&camera->orientation);
	rt_print_indent(0);
	printf("fov: %d\n", camera->fov);
}
