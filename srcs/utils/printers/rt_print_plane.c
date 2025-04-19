/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_print_plane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:47:51 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/19 22:31:09 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rt_print_plane(const t_plane *plane)
{
	if (plane == NULL)
		return ;
	printf("		position: ");
	rt_print_vector(&plane->position);
	printf("		orientation: ");
	rt_print_vector(&plane->orientation);
}
