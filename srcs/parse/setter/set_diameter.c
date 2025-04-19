/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_diameter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:15:18 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/19 18:15:26 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	set_diameter(void *diameter, char *str, size_t *j)
{
	float	*diameter_f;

	diameter_f = (float *)diameter;
	*diameter_f = ft_atof_index_dev(str, j, false);
	if (*diameter_f < 0.0f)
		return (error_message(RADIUS_RANGE), false);
	return (true);
}
