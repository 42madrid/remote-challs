/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jtrancos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrancos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 18:37:55 by jtrancos          #+#    #+#             */
/*   Updated: 2020/05/09 20:06:47 by jtrancos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <ctype.h>

char *check_format(char *seconds)
{
	while (*seconds)
	{
		if (isdigit(*seconds) == 0)
			return ("Invalid input.");
		seconds++;
	}
	if (seconds == "0")
		return ("now");
	else if (seconds == "")
		return ("Invalid input.");
	else
		return (0);
}
char *ft_format_duration(char *seconds)
{
	if (check_format(seconds) != 0)
		return (check_format(seconds));
}

int main ()
{
	printf("%s\n", ft_format_duration("62"));
	return (0);
}
