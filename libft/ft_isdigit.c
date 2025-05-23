/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_isdigit.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mfukui <mfukui@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/09/20 02:28:10 by mfukui			#+#	#+#			 */
/*   Updated: 2023/09/27 00:41:02 by mfukui		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int s)
{
	if ('0' <= s && s <= '9')
		return (1);
	return (0);
}
