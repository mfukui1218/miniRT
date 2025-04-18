/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:38:21 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/19 21:11:05 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_color(t_color *color)
{
	free(color);
	color = NULL;
}
