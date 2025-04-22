/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_diameter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:15:18 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/22 17:13:02 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	set_diameter(void *diameter, char *str, size_t *j)
{
	double	*diameter_f;

	diameter_f = (double *)diameter;
	*diameter_f = ft_atod_index_dev(str, j, false);
	if (*diameter_f < 0.0f)
		return (error_message(RADIUS_RANGE), false);
	return (true);
}
