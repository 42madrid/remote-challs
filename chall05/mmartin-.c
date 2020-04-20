/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmartin-.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 08:50:33 by mmartin-          #+#    #+#             */
/*   Updated: 2020/04/17 09:16:32 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	DESCRIPTION
**		Checks whether a sentence follows the rule 'I before E except after C'
**	HOW IT WORKS
**		While there are more characters to read, check whether the rules are OK
**	RETURN VALUES
**		Boolean, if _str_ follow the rule it will be true
*/

int		ft_ie_except_after_c(char *str)
{
	while (*(str + 1))
		if (*(str - 1) != 'c' && *str == 'e' && *(str + 1) == 'i')
			return (0);
		else if (*str == 'c' && *(str + 1) == 'i' && *(str + 2) == 'e')
			return (0);
		else
			str++;		
	return (1);
}
