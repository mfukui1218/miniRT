/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message_parse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:27:45 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/19 18:27:49 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	error_message_parse(int err)
{
	if (err == CAMERA)
		printf("This cause is  camera format\n");
	else if (err == AMBIENT)
		printf("This cause is ambient format\n");
	else if (err == LIGHT)
		printf("This cause is light format\n");
	else if (err == OBJECT)
		printf("This cause is object format\n");
	else
		return (false);
	return (true);
}
