/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_print_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:49:34 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/20 01:13:39 by tookuyam         ###   ########.fr       */
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
	rt_print_indent(0);
	printf("radius: %f\n", cylinder->radius);
	rt_print_indent(0);
	printf("height: %f\n", cylinder->height);
}
