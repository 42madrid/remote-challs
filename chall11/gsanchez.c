/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gsanchez.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsanchez <gsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 23:20:53 by gsanchez          #+#    #+#             */
/*   Updated: 2020/05/22 11:32:12 by gsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char  **ft_parse_nlarray(char *src, int newsize)
{
  char  **arr;
  int   j;

  arr = malloc(sizeof(char*)*newsize);
  j = 0;
  while (j != newsize)
      arr[j++] = strtok_r(src, "\n", &src);
  return (arr);
}

char  *ft_goto_parser(const char *code)
{
    char *buf, *result, *aux, *rest, *token;
    char **arr;
    int i, j, indextogo;

    buf = strdup(code);
    rest = buf;
    for (i=0; buf[i]; buf[i]=='\n' ? i++ : *buf++);
    arr = ft_parse_nlarray(rest, i);
    result = NULL;
    j = 0;
    while (j < i)
    {
      if (isdigit(*arr[j]))
      {
        while (isdigit(*arr[j]))
          arr[j]++;
        rest = arr[j];
        while (token = strtok_r(rest, " ", &rest))
        {
          aux = result;
          if (!aux)
            asprintf(&result, "%s", token);
          else
          {
            asprintf(&result, "%s %s", result, token);
            free(aux);
          }
        }
      }
      else if (strstr(arr[j], "goto"))
      {
        indextogo = atoi(arr[j]+4);
        j = 0;
        while (++j < i)
          if (indextogo == atoi(arr[j]))
              break;
        if (j == i)
          return (strdup("Infinite loop !"));
        continue;
      }
      j++;
    }
    free(arr);
    return (result);
}
