/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_print_indent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:46:22 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/20 00:46:22 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <stdio.h>

/**
 * @brief Print indent
 * @param indent != 0 add the indentation level. == 0 print indent
 */
void	rt_print_indent(int indent)
{
	static int	indent_level;

	if (indent != 0)
	{
		indent_level += indent;
		return ;
	}
	printf("%*s", indent_level * INDENT_SIZE, "");
}
