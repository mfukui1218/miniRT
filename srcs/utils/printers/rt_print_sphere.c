/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_print_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:44:37 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/20 01:12:56 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rt_print_sphere(const t_sphere *sphere)
{
	if (sphere == NULL)
		return ;
	rt_print_str("position: ");
	rt_print_vector(&sphere->position);
	rt_print_indent(0);
	printf("radius: %f\n", sphere->radius);
}
