/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_radius.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:26:07 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/19 18:26:15 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	error_radius(int err)
{
	if (err == RADIUS_RT)
		printf("Error\nInvalid radius format\n");
	else if (err == RADIUS_RANGE)
		printf("Error\nRadius out of range\n");
	else
		return (false);
	return (true);
}