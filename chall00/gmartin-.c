/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gmartin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 18:06:55 by gmartin-          #+#    #+#             */
/*   Updated: 2019/10/09 12:40:08 by gmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  Para resolver este ejercicio he utilizado las funciones con las que hemos estado trabajando
	para practicar con ellas. 
	En primer lugar utilizamos la funcion itoa que convierte dígitos a caracteres, pero con la 
	funcionalidad en este caso para que al mismo tiempo que vamos guardandolo en nuestro string 
	los estemos convirtiendo a hexadecimal. Para ello simplemente calculamos los módulos de 
	los digitos que nos han dado y vamos pasandolo a hexadecimal.
	Una vez que tenemos los dígitos r, g y b en hexadecimal y convertidos a carácteres utilizamos la función
	ft_strjoin para concatenarlos. Necesitaremos la funcion ft_strlen que mide el tamaño de los string que va
	a concatenar para hacer la reserva de memoria previa.   */

size_t	ft_strlen(const char *s)							// Con esta función conocemos el tamaño de cada string.
{
	size_t x;

	x = 0;
	while (s[x] != '\0')
	{
		x++;
	}
	return (x);
}

char	*ft_strjoin(char const *s1, char const *s2) 		// Con esta función concatenamos los strings de r, g y b.
{
	char	*dst;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (!s1 || !s2)
		return (NULL);
	dst = malloc(sizeof(*dst) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (dst == NULL)
		return (NULL);
	while (s1[x])
	{
		dst[x] = s1[x];
		x++;
	}
	while (s2[y])
	{
		dst[x] = s2[y];
		x++;
		y++;
	}
	dst[x] = '\0';
	return (dst);
}
char    *ft_itoa(int n) 									// Para convertir los dígitos a caracteres, previo cálculo para pasar a hexadecimal.
{
	int		aux;
	int		len;
	char	*str;
	
	aux = n;
	len = 2; 												// Sabemos que el tamaño de cada string será 2, no hace falta calcularlo. 
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[len] = '\0';
	if (aux/16 < 1) 										// Comprobamos si el dígito que nos dan es < a 16, en ese caso nuestro nuevo dígito 
		str[0] = '0';										// en hexadecimal solo será representado por un carácter y tendremos que rellenar con
	while (len--)											// '0' la primera posición para que nuestro string siempre este formado por 2 carácteres.
	{
		if ((n % 16) < 10)
			str[len] = n % 16 + '0';						// Pasos para convertir en hexadecimal a la vez que guardamos en nuestro string.
		if ((n % 16) > 9)
			str[len] = n % 16 + 'W';
		n = n / 16;
	}
	return (str);											// Cada vez que entremos en la función devolverá r, g o b convertido a hexadecimal 
}															// y como un string.

char    *hv_rgb2hex(int r, int g, int b)					// Función principal. Recibe 3 dígitos para convertirlos en un string "rgb".
{
	char    *rgb;
	rgb = "#";												// Nuestro string siempre comenzara con "#".
	if (r < 0 || g < 0 || b < 0)							// Comprobación por si se introduce un número negativo.
		return("Error: Introduce numeros posivitos.");
	rgb = ft_strjoin(rgb, ft_itoa(r));						// Vamos mandando los datos de r, g y b para su calculo, conversión y concatenación.
	rgb = ft_strjoin(rgb, ft_itoa(g));
	rgb = ft_strjoin(rgb, ft_itoa(b));
	return(rgb);											// Retorno de nuestro "rgb" final. 
}
