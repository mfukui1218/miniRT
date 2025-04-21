/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_print_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:49:34 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/22 01:09:54 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rt_print_cylinder(const t_cylinder *cylinder)
{
	if (cylinder == NULL)
		return ;
	rt_print_str("position: ");
	rt_print_vector(&cylinder->position);
	rt_print_str("orientation: ");
	rt_print_vector(&cylinder->orientation);
	rt_print_indent(PRINT_INDENT);
	printf("radius: %f\n", cylinder->radius);
	rt_print_indent(PRINT_INDENT);
	printf("height: %f\n", cylinder->height);
	printf("color: %d,%d,%d\n", cylinder->color.r, cylinder->color.g, cylinder->color.b);
}
