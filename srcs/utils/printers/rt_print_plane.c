/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_print_plane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:47:51 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/22 01:09:44 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rt_print_plane(const t_plane *plane)
{
	if (plane == NULL)
		return ;
	rt_print_str("position: ");
	rt_print_vector(&plane->position);
	rt_print_str("orientation: ");
	rt_print_vector(&plane->orientation);
	printf("color: %d,%d,%d\n", plane->color.r, plane->color.g, plane->color.b);
}
