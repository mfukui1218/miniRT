/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_normalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:03:31 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/22 16:44:56 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	vec_normalize(t_vector v)
{
	float		length;
	t_vector	result;

	length = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
	if (length == 0)
		return ((t_vector){0, 0, 0});
	result.x = v.x / length;
	result.y = v.y / length;
	result.z = v.z / length;
	return (result);
}
