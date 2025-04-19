/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message_common.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:03:19 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/19 20:43:12 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	error_message_common(int err)
{
	if (err == MLX)
		printf("Error\nMLX error\n");
	else if (err == WIN)
		printf("Error\nWindow error\n");
	else if (err == ALLOCATE)
		printf("Error\nAllocation error\n");
	else if (err == OPEN)
		printf("Error\nFile open error\n");
	else
		return (false);
	return (true);
}

