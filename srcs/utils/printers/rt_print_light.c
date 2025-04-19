/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_print_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:20:12 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/20 01:11:53 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rt_print_light(const t_light *light)
{
	if (light == NULL)
		return ;
	rt_print_str("position: ");
	rt_print_vector(&light->position);
	rt_print_indent(0);
	printf("brightness: %f\n", light->brightness);
	rt_print_str("color: ");
	rt_print_color(&light->color);
}
