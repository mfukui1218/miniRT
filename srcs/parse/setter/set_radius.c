/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_radius.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:48:47 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/19 18:14:28 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	set_radius(void *radius, char *str, size_t *j)
{
	float	*radius_f;

	radius_f = (float *)radius;
	*radius_f = ft_atof_index_dev(str, j, true);
	if (*radius_f < 0.0f)
		return (error_message(RADIUS_RANGE), false);
	return (true);
}
