/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isoria-g.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yo <yo@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 00:02:38 by marvin            #+#    #+#             */
/*   Updated: 2020/05/11 10:19:38 by yo               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// Modificación para subir de nuevo según solicitado en slack 


#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t      ft_strlen(const char *s)
{
    size_t  a;

    a = 0;
    while (s[a] != '\0')
        a++;
    return (a);
}

char                *ft_strjoin(char *s1, char *s2)
{
    unsigned int    a;
    unsigned int    l1;
    unsigned int    l2;
    char            *t;
    char            *str1;

    a = 0;
    if (s1 == NULL || s2 == NULL)
        return (NULL);
    l1 = (unsigned int)ft_strlen((char *)s1);
    l2 = (unsigned int)ft_strlen((char *)s2);
    if (!(t = (char *)malloc((l1 + l2) * sizeof(char) + 1)))
        return (NULL);
    str1 = (char *)t;
    while (a < (l1 + l2))
    {
        if (a < l1)
            str1[a] = s1[a];
        else
            str1[a] = s2[a - l1];
        a++;
    }
    str1[a] = '\0';
    return (t);
}

static unsigned long long   ft_value(unsigned long long n)
{
    unsigned long long      b;

    if (n < 0)
        b = n * (-1);
    else
        b = n;
    return (b);
}

static unsigned long long   ft_size(unsigned long long b)
{
    unsigned long long      a;

    a = 0;
    while (b > 9)
    {
        b = b / 10;
        a++;
    }
    return (a);
}

static unsigned long long   ft_end(unsigned long long n)
{
    unsigned long long      c;

    if (n < 0)
        c = ft_size(ft_value(n)) + 2;
    else
        c = ft_size(ft_value(n)) + 1;
    return (c);
}

static char *ft_zero(char *p)
{
    char    *pp;

    pp = (char *)malloc(1 * sizeof(char) + 1);
    pp = p;
    pp[0] = '0';
    pp[1] = '\0';
    return (pp);
}

char                    *ft_itoa(unsigned long long n)
{
    unsigned long long  a;
    unsigned long long  b;
    char                *p;

    a = 0;
    b = ft_value(n);
    if (!(p = (char *)malloc((ft_size(b) + 2) * sizeof(char) + 1)))
        return (NULL);
    if (n == 0)
        return (ft_zero(p));
    if (n < 0)
        p[a] = 45;
    if (n < 0)
        a = ft_size(ft_value(n)) + 1;
    else
        a = ft_size(ft_value(n));
    while (b > 9)
    {
        p[a--] = (b % 10) + 48;
        b = b / 10;
    }
    p[a] = (b % 10) + 48;
    p[ft_end(n)] = '\0';
    return (p);
}

char    *ft_isspace(char *str)
{
    int i;

    i = 0;
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    return (&str[i]);
}

unsigned long long      ft_atoi(char *str)
{   
    char                *ptr;
    int                 i;
    int                 j;
    int                 k;
    unsigned long long  nb;
    unsigned long long  total;

    i = 0;
    k = 0;
    ptr = ft_isspace(str);
    if (ptr[0] < '0' || ptr[0] > '9')
        return (-1);
    j = 0;
    while ((ptr[j] >= '0' && ptr[j] <= '9') || ptr[j] == 32)
    {
        if (ptr[j] == 32)
            k++;
        if ((ptr[j] >= '0' && ptr[j] <= '9') && k > 0)
            return(-1);
        j++;
    }
    if (ptr[j] != '\0')
        return (-1);
    i = 0;
    total = 0;
    while (i < j - k)
    {
        nb = ptr[i] - '0';
        total = total + nb;
        if (i < j - k - 1)
            total = total * 10;
        i++;
    }
    return (total);
}

char                    *ft_format_duration(char *seconds)
{
    unsigned long long  nb;
    unsigned long long  yy;
    unsigned long long  dd;
    unsigned long long  hh;
    unsigned long long  mm;
    unsigned long long  ss;
    char *str = "";

    if (seconds == NULL)
        return("\"Invalid input.\"");
    nb = ft_atoi(seconds);
    if (nb == -1)
        return("\"Invalid input.\"");
    if (nb == 0)
        return("\"now\"");
    yy = nb / 31536000;
    dd = (nb % 31536000) / 86400;
    hh = ((nb % 31536000) % 86400) / 3600;
    mm = (((nb % 31536000) % 86400) % 3600) / 60;
    ss = (((nb % 31536000) % 86400) % 3600) % 60;
    str = ft_strjoin(str, "\"");
    if (yy > 0)
    {
        if (yy == 1)
        {
            str = ft_strjoin(str, ft_itoa(yy));
            str = ft_strjoin(str, " year");
        }
        else
        {
            str = ft_strjoin(str, ft_itoa(yy));
            str = ft_strjoin(str, " years");
        }
    }
    if (dd > 0 && (hh > 0 || mm > 0 || ss > 0))
    {
        if (yy > 0)
            str = ft_strjoin(str, ", ");
        if (dd == 1)
        {
            str = ft_strjoin(str, ft_itoa(dd));
            str = ft_strjoin(str, " day");
        }
        else
        {
            str = ft_strjoin(str, ft_itoa(dd));
            str = ft_strjoin(str, " days");
        }
    }
    else if (dd > 0)
    {
        if (yy > 0)
            str = ft_strjoin(str, " and ");
        if (dd == 1)
        {
            str = ft_strjoin(str, ft_itoa(dd));
            str = ft_strjoin(str, " day");
        }
        else
        {
            str = ft_strjoin(str, ft_itoa(dd));
            str = ft_strjoin(str, " days");
        }
    }
    if (hh > 0 && (mm > 0 || ss > 0))
    {
        if (yy > 0 || dd > 0)
            str = ft_strjoin(str, ", ");
        if (hh == 1)
        {
            str = ft_strjoin(str, ft_itoa(hh));
            str = ft_strjoin(str, " hour");
        }
        else
        {
            str = ft_strjoin(str, ft_itoa(hh));
            str = ft_strjoin(str, " hours");
        }
    }
    else if (hh > 0)
    {
        if (yy > 0 || dd > 0)
            str = ft_strjoin(str, " and ");
        if (hh == 1)
        {
            str = ft_strjoin(str, ft_itoa(hh));
            str = ft_strjoin(str, " hour");
        }
        else
        {
            str = ft_strjoin(str, ft_itoa(hh));
            str = ft_strjoin(str, " hours");
        }
    }
    if (mm > 0 && (ss > 0))
    {
        if (yy > 0 || dd > 0 || hh > 0)
            str = ft_strjoin(str, ", ");
        if (mm == 1)
        {
            str = ft_strjoin(str, ft_itoa(mm));
            str = ft_strjoin(str, " minute");
        }
        else
        {
            str = ft_strjoin(str, ft_itoa(mm));
            str = ft_strjoin(str, " minutes");
        }
    }
    else if (mm > 0)
    {
        if (yy > 0 || dd > 0 || hh > 0)
            str = ft_strjoin(str, " and ");
        if (mm == 1)
        {
            str = ft_strjoin(str, ft_itoa(mm));
            str = ft_strjoin(str, " minute");
        }
        else
        {
            str = ft_strjoin(str, ft_itoa(mm));
            str = ft_strjoin(str, " minutes");
        }
    }
    if (ss > 0 && (yy > 0 || dd > 0 || hh > 0 || mm > 0))
    {
        str = ft_strjoin(str, " and ");
        if (ss == 1)
        {
            str = ft_strjoin(str, ft_itoa(ss));
            str = ft_strjoin(str, " second");
        }
        else
        {
            str = ft_strjoin(str, ft_itoa(ss));
            str = ft_strjoin(str, " seconds");
        }
    }
    else if (ss > 0)
    {
        if (ss == 1)
        {
            str = ft_strjoin(str, ft_itoa(ss));
            str = ft_strjoin(str, " second");
        }
        else
        {
            str = ft_strjoin(str, ft_itoa(ss));
            str = ft_strjoin(str, " seconds");
        }
    }
    str = ft_strjoin(str, "\"");
    return (str);
}