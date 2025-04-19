/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_print_ambient.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:35:31 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/19 18:29:42 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rt_print_ambient(const t_ambient *ambient)
{
	if (ambient == NULL)
		return ;
	printf("{\n");
	printf("	brightness: %f\n", ambient->brightness);
	printf("	color: ");
	rt_print_color(&ambient->color);
	printf("\n");
	printf("}\n");
}
