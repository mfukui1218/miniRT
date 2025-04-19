/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:25:36 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/19 18:25:39 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	error_cylinder(int err)
{
	if (err == CYLINDER_RT)
		printf("Error\nInvalid cylinder format\n");
	else if (err == CYLINDER_RANGE)
		printf("Error\nCylinder out of range\n");
	else
		return (false);
	return (true);
}
