/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_print_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:44:37 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/22 01:09:31 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rt_print_sphere(const t_sphere *sphere)
{
	if (sphere == NULL)
		return ;
	rt_print_str("position: ");
	rt_print_vector(&sphere->position);
	rt_print_indent(PRINT_INDENT);
	printf("radius: %f\n", sphere->radius);
	printf("color: %d,%d,%d\n", sphere->color.r, sphere->color.g, sphere->color.b);
}
