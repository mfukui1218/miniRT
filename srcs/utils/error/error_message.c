/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:24:44 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/19 18:24:49 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	error_message(int err)
{
	if (error_message_common(err))
		return ;
	if (error_message_parse(err))
		return ;
	if (error_message_value(err))
		return ;
	printf("Error\nUnknown error\n");
}
