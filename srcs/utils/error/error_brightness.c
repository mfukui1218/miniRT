/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_brightness.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:27:09 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/19 18:27:16 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	error_brightness(int err)
{
	if (err == BRIGHTNESS_RT)
		printf("Error\nInvalid brightness format\n");
	else if (err == BRIGHTNESS_RANGE)
		printf("Error\nBrightness out of range\n");
	else
		return (false);
	return (true);
}
