/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_isalpha.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mfukui <mfukui@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/09/20 02:25:42 by mfukui			#+#	#+#			 */
/*   Updated: 2023/09/27 02:00:55 by mfukui		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int s)
{
	if (('a' <= s && s <= 'z') || ('A' <= s && s <= 'Z'))
		return (1);
	return (0);
}
