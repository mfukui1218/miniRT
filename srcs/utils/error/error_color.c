/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:26:57 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/19 21:09:26 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	error_color(int err)
{
	if (err == COLOR_RT)
		printf("Error\nInvalid color format\n");
	else if (err == COLOR_RANGE)
		printf("Error\nColor out of range\n");
	else
		return (false);
	return (true);
}
