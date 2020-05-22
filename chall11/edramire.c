/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edramire.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edramire <edramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 23:56:08 by edramire          #+#    #+#             */
/*   Updated: 2020/05/22 10:30:15 by edramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

typedef	struct	s_list{
	char const		*key;
	size_t			key_len;
	char const		*value;
	size_t			value_len;
	int				visited;
	struct s_list	*next;
	struct s_list	*goto_line;
}				t_list;

static int		ft_stc_free_list(t_list *lst)
{
	t_list		*aux;

	while (lst != NULL)
	{
		aux = lst;
		lst = lst->next;
		free(aux);
	}
	return (1);
}

static t_list	*ft_stc_load(const char *code)
{
	t_list	*list;
	t_list	*node;
	t_list	*last;

	list = NULL;
	while (*code != '\0')
	{
		node = malloc(sizeof(t_list));
		if (node == NULL && ft_stc_free_list(list))
			return (NULL);
		bzero(node, sizeof(t_list));
		if (list == NULL)
			list = node;
		else
			last->next = node;
		node->key = code;
		node->value = strchr(code, ' ') + 1;
		node->key_len = (node->value - node->key) - 1;
		node->value_len = (strchr(code, '\n') - node->value);
		code = strchr(code, '\n') + 1;
		last = node;
	}
	return (list);
}

static void		ft_stc_find_destination(t_list *list, t_list *node)
{
	size_t len;

	len = 0;
	if (isdigit(*node->key))
	{
		node->goto_line = node->next;
		return ;
	}
	while (*node->value == ' ')
		++node->value;
	while (isdigit(*(node->value + len)))
		++len;
	node->value_len = len;
	while (list != NULL)
	{
		if (list->key_len == len && strncmp(list->key, node->value, len) == 0)
		{
			node->goto_line = list;
			return ;
		}
		list = list->next;
	}
}

static size_t	ft_stc_strncpy(char *str, size_t from, t_list *node)
{
	while (*node->value == ' ')
		++node->value;
	while (*node->value != '\n')
	{
		str[from++] = *node->value;
		if (*node->value == ' ')
			while (*node->value == ' ')
				++node->value;
		else
			++node->value;
	}
	if (str[from - 1] != ' ')
		str[from++] = ' ';
	str[from] = '\0';
	return (from);
}

char			*ft_goto_parser(const char *code)
{
	t_list	*list;
	t_list	*aux;
	char	*str;
	size_t	len;

	list = ft_stc_load(code);
	if (list == NULL)
		return (NULL);
	str = malloc(strlen(code) * sizeof(char));
	if (str == NULL && ft_stc_free_list(list))
		return (NULL);
	aux = list;
	len = 0;
	while (aux != NULL)
	{
		if (aux->visited == 1 && ft_stc_free_list(list))
		{
			strcpy(str, "Infinite loop !");
			return (str);
		}
		aux->visited = 1;
		ft_stc_find_destination(list, aux);
		if (isdigit(*aux->key))
			len = ft_stc_strncpy(str, len, aux);
		aux = aux->goto_line;
	}
	ft_stc_free_list(list);
	str[--len] = '\0';
	return (str);
}
