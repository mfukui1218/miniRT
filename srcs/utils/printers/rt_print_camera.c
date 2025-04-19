/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_print_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:20:21 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/19 22:14:18 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rt_print_camera(const t_camera *camera)
{
	if (camera == NULL)
		return ;
	printf("{\n");
	printf("	position: ");
	rt_print_vector(&camera->position);
	printf("\n");
	printf("	orientation: ");
	rt_print_vector(&camera->orientation);
	printf("\n");
	printf("	fov: %d\n", camera->fov);
	printf("}\n");
}
