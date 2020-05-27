/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edramire.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edramire <edramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 13:54:51 by edramire          #+#    #+#             */
/*   Updated: 2020/05/25 16:46:16 by edramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct		s_list
{
	char			letter;
	int				operator;
	struct s_list	*next;
}					t_list;

static int			ft_stc_free(t_list *list, char *response)
{
	t_list	*aux;

	free(response);
	while (list != NULL)
	{
		aux = list;
		list = list->next;
		free(aux);
	}
	return (1);
}

static t_list		*ft_stc_create(char letter, int operator)
{
	t_list		*aux;

	aux = malloc(sizeof(t_list));
	if (aux == NULL)
		return (NULL);
	aux->letter = letter;
	aux->operator = operator;
	aux->next = NULL;
	return (aux);
}

static void			ft_stc_push(t_list **list, t_list *node)
{
	t_list	*aux;

	if (list == NULL)
		return ;
	if (*list == NULL)
		*list = node;
	else
	{
		aux = *list;
		while (aux->next != NULL)
			aux = aux->next;
		aux->next = node;
	}
}

static t_list		*ft_stc_pop(t_list **list)
{
	t_list		*last;
	t_list		*aux;

	if (list == NULL)
		return (NULL);
	aux = *list;
	last = NULL;
	while (aux != NULL)
	{
		if (aux->next == NULL)
		{
			if (last == NULL)
				*list = NULL;
			else
				last->next = NULL;
			break ;
		}
		last = aux;
		aux = aux->next;
	}
	return (aux);
}

static t_list		*ft_stc_head(t_list **list)
{
	t_list		*aux;

	if (list == NULL || *list == NULL)
		return (NULL);
	aux = *list;
	*list = (*list)->next;
	aux->next = NULL;
	return (aux);
}

static void			ft_stc_reverse_stack(t_list **list)
{
	t_list		*node;
	t_list		*aux;

	aux = NULL;
	node = ft_stc_pop(list);
	while (node->operator != 1)
	{
		ft_stc_push(&aux, node);
		node = ft_stc_pop(list);
	}
	node->operator = 0;
	ft_stc_push(&aux, node);
	while (aux != NULL)
	{
		node = ft_stc_head(&aux);
		if (node->letter == '(' || node->letter == ')')
			node->letter = node->letter == '(' ? ')' : '(';
		ft_stc_push(list, node);
	}
}

char				*ft_reverse_parenthesis(const char *str)
{
	t_list		*list;
	t_list		*node;
	int			operators;
	char		*response;

	list = NULL;
	node = NULL;
	operators = 0;
	if (str == NULL)
		return (NULL);
	response = malloc(strlen(str) + 1);
	if (response == NULL)
		return (NULL);
	while (*str != '\0')
	{
		node = ft_stc_create(*str, *str == '(' ? 1 : 0);
		if (node == NULL && ft_stc_free(list, response))
			return (NULL);
		if (node->letter == ')')
		{
			if (--operators < 0)
				break ;
			ft_stc_push(&list, node);
			ft_stc_reverse_stack(&list);
		}
		else if (node->letter == '(')
		{
			++operators;
			ft_stc_push(&list, node);
		}
		else
			ft_stc_push(&list, node);
		++str;
	}
	if (operators != 0 && ft_stc_free(list, response))
		return (NULL);
	node = list;
	operators = 0;
	while (node != NULL)
	{
		response[operators++] = node->letter;
		node = node->next;
	}
	response[operators] = '\0';
	ft_stc_free(list, NULL);
	return (response);
}
