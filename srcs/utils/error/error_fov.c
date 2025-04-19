/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_fov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:26:42 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/19 18:26:48 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	error_fov(int err)
{
	if (err == FOV_RT)
		printf("Error\nInvalid fov format\n");
	else if (err == FOV_RANGE)
		printf("Error\nFov out of range\n");
	else
		return (false);
	return (true);
}
