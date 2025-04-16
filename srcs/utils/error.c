/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:03:19 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/16 13:50:07 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	error_message(int eroor)
{
	if (eroor == ALLOCATE)
		printf("Error\nAllocation error\n");
	else if (eroor == OPEN)
		printf("Error\nFile open error\n");
	else if (eroor == COORDINATE_RT)
		printf("Error\nInvalid coordinate format\n");
	else if (eroor == COORDINATE_RANGE)
		printf("Error\nCoordinate out of range\n");
	else if (eroor == BRIGHTNESS_RT)
		printf("Error\nInvalid brightness format\n");
	else if (eroor == BRIGHTNESS_RANGE)
		printf("Error\nBrightness out of range\n");
	else if (eroor == COLOR_RT)
		printf("Error\nInvalid color format\n");
	else if (eroor == COLOR_RANGE)
		printf("Error\nColor out of range\n");
	else if (eroor == FOV_RT)
		printf("Error\nInvalid fov format\n");
	else if (eroor == FOV_RANGE)
		printf("Error\nFov out of range\n");
	else
		printf("Error\nUnknown error\n");
	exit(0);
}

