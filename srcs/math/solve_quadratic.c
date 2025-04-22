/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quadratic(.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:03:31 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/22 16:26:29 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	solve_quadratic(float a, float b, float discriminant)
{
	float	t1;
	float	t2;

	if (discriminant < 0)
		return (-1.0f);
	t1 = (-b - sqrtf(discriminant)) / (2.0f * a);
	t2 = (-b + sqrtf(discriminant)) / (2.0f * a);
	if (t1 > 0.001f)
		return (t1);
	else if (t2 > 0.001f)
		return (t2);
	return (-1.0f);
}
