/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:00:34 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/19 18:30:24 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_camera(t_camera *camera)
{
	camera->position = (t_vector){0, 0, 0};
	camera->orientation = (t_vector){0, 0, -1};
	camera->fov = 0;
}
