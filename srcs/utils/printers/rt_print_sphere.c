/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_print_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:44:37 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/19 22:31:04 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rt_print_sphere(const t_sphere *sphere)
{
	if (sphere == NULL)
		return ;
	printf("{\n");
	printf("		position: ");
	rt_print_vector(&sphere->position);
	printf("\n");
	printf("		radius: %f\n", sphere->radius);
	printf("	}\n");
}
