/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_print_ambient.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:35:31 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/20 01:34:48 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rt_print_ambient(const t_ambient *ambient)
{
	if (ambient == NULL)
		return ;
	rt_print_indent(PRINT_INDENT);
	printf("brightness: %f\n", ambient->brightness);
	rt_print_str("color: ");
	rt_print_color(&ambient->color);
}
