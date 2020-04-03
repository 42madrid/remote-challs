/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmartin-.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 16:46:55 by mmartin-          #+#    #+#             */
/*   Updated: 2020/04/03 03:27:51 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
**	DESCRIPTION
**		Checks for string similarity
**	HOW ITS DONE
**		(Compiled using clang for Ubuntu WSL)
**
**		Checks for valid input or for two equal strings,
**		copy into a temporal array _s1_ twice so let _s1_ be "nicole",
**		the temporal array would be nicolenicole.
**		Then generates every combination adding one to each iteration. Given in:
**			nicole - icolen - coleni - olenic - lenico - enicol
**		If any of the combinations matches _s2_, it is considered a similar str
**	RETURN VALUES
**		1 if considered valid, 0 otherwise
*/

int		hv_necklace(char *s1, char *s2)
{
	int		count;
	char	strc[strlen(s1) * 2 + 1];

	if (!s1 || !s2 || strlen(s1) != strlen(s2))
		return (0);
	if (!strcmp(s1, s2))
		return (1);
	count = -1;
	strcpy(strc, s1);
	strcpy(strc + strlen(s1), s1);
	while (++count < (int)strlen(s1))
		if (!strncmp(strc + count, s2, strlen(s1)))
			return (1);
	return (0);
}
