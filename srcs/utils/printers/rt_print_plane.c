/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_print_plane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:47:51 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/20 01:13:18 by tookuyam         ###   ########.fr       */
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
}
