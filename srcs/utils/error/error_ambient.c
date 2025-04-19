/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:24:10 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/19 18:25:10 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	error_ambient(int err)
{
	if (err == AMBIENT_RT)
		printf("Error\nInvalid ambient format\n");
	else if (err == AMBIENT_RANGE)
		printf("Error\nAmbient out of range\n");
	else
		return (false);
	return (true);
}
