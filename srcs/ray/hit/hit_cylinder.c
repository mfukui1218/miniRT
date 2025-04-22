/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:34:42 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/22 16:38:49 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	hit_cylinder(t_ray ray, t_cylinder *cylinder, float *t)
{
	bool	hit;
	float	t_body;
	float	t_caps;

	hit = false;
	if (hit_cylinder_body(ray, cylinder, &t_body))
	{
		*t = t_body;
		hit = true;
	}
	if (hit_cylinder_caps(ray, cylinder, &t_caps))
	{
		if (!hit || t_caps < *t)
			*t = t_caps;
		hit = true;
	}
	return (hit);
}
