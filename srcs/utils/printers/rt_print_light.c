/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_print_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:20:12 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/19 18:29:49 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rt_print_light(const t_light *light)
{
	if (light == NULL)
		return ;
	printf("	position: ");
	rt_print_vector(&light->position);
	printf("	brightness: %f\n", light->brightness);
	printf("	color: ");
	rt_print_color(&light->color);
}
