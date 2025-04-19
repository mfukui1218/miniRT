/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:26:25 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/19 18:26:30 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	error_vector(int err)
{
	if (err == VECTOR_RT)
		printf("Error\nInvalid vector format\n");
	else if (err == VECTOR_RANGE)
		printf("Error\nVector out of range\n");
	else
		return (false);
	return (true);
}
