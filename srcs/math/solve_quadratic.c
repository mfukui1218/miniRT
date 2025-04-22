/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quadratic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:03:31 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/22 17:11:49 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	solve_quadratic(double a, double b, double discriminant)
{
	double	t1;
	double	t2;

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
