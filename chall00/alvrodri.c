#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*ft_itoa_base(unsigned int nbr, char *base, int len)
{
	unsigned int	n;
	int				i;
	char			*str;

	n = nbr;
	i = 2;
	/* Calculamos cuantos bytes hay que alocar contando las cifras que tendrá nuestro número en base 'len' */
	while ((n /= len) > 0)
		i++;
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	/* El último caracter debe ser '\0' */
	str[i] = '\0';
	while (i--)
	{
		/* Si el módulo del número es mayor o igual a 10 igualamos str[i] a el caracter que haya en la posición 'nbr % len' en la array base */
		str[i] = (nbr % len >= 10) ? base[nbr % len] : (nbr % len) + '0';
		nbr /= len;
	}
	/* El primer caracter debe ser'#' */
	str[0] = '#';
	return (str);
}

char	*hv_rgb2hex(int r, int g, int b)
{
	/* Ejemplo con 255, 255, 255 */
	/* Muevo 'r' 16 bits a la izquierda (ff0000), muevo 'g' 8 bits a la izquierda (ffff00), muevo 'b' 0 bits a la izquierda (ffffff) */
    unsigned int	hex = r << 16 | g << 8 | b;
	return (ft_itoa_base(hex, "0123456789abcdef", 16));
}