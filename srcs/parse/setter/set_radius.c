/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_radius.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:48:47 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/22 17:13:02 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	set_radius(void *radius, char *str, size_t *j)
{
	double	*radius_f;

	radius_f = (double *)radius;
	*radius_f = ft_atod_index_dev(str, j, true);
	if (*radius_f < 0.0f)
		return (error_message(RADIUS_RANGE), false);
	return (true);
}
