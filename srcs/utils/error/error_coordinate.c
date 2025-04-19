/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_coordinate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:25:54 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/19 18:27:29 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	error_coordinate(int err)
{
	if (err == COORD_RT)
		printf("Error\nInvalid coordinate format\n");
	else if (err == COORD_RANGE)
		printf("Error\nCoordinate out of range\n");
	else
		return (false);
	return (true);
}
