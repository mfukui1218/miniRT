/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_print_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:49:34 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/19 22:31:05 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "miniRT.h"

void	rt_print_cylinder(const t_cylinder *cylinder)
{
	if (cylinder == NULL)
		return ;
	printf("{\n");
	printf("		position: ");
	rt_print_vector(&cylinder->position);
	printf("\n");
	printf("		orientation: ");
	rt_print_vector(&cylinder->orientation);
	printf("\n");
	printf("		radius: %f\n", cylinder->radius);
	printf("		height: %f\n", cylinder->height);
	printf("	}\n");
}
