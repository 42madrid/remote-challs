#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct	s_format
{
	char    *result;
    char    *num_lines;
    char    *str_go_to;
    char    *duplicate;
    char    *temp;
    int     position;
    int     positioin_result;
    int     len;
}				t_format;

void	carrier_init(t_format *carrier)
{
	carrier->result = strdup("");
    carrier->num_lines = strdup("");
    carrier->str_go_to = strdup("");
    carrier->temp = strdup("");
    carrier->position = 0;
    carrier->positioin_result = 0;
}

void	print_struct(t_format *carrier)
{
	printf("\n");
	printf("duplicate: \n%s\n", carrier->duplicate);
    printf("          result: %s\n", carrier->result);
	printf("       num_lines: %s\n", carrier->num_lines);
	printf("            temp: %s\n", carrier->temp);
    printf("             len: %d\n", carrier->len);
    printf("        position: %d\n", carrier->position);
    printf(" position_result: %d\n", carrier->positioin_result);
    
}

char    *del_spaces(t_format *carrier)
{
    int i;
    int j;

    i = 0;
    while (carrier->duplicate[i] != '\0')
    {
        while (isblank(carrier->duplicate[i]) && isblank(carrier->duplicate[i + 1]))
        {
            j = i;
            while (j <= carrier->len)
            {    
                carrier->duplicate[j] = carrier->duplicate[j + 1];
                j++;
            }
        }
        i++;
    }
    return (carrier->duplicate);
}

void    loop(t_format *carrier)
{
    int     i;
    int     j;
    
    i = 0;
    j = 0;
    while (!isdigit(carrier->temp[i]))
        i++;
    printf("temp[%c]: %c", i, carrier->temp[i]);
    while (isdigit(carrier->temp[i]))
    {
        carrier->str_go_to[j] = carrier->temp[i];
        i++;
        j++;
    }
    carrier->str_go_to = strcat(carrier->str_go_to, " ");
    printf("\ngo_to_loop: %s.\n", carrier->str_go_to);
    if (strstr(carrier->num_lines, carrier->str_go_to))
    {    
        printf("%s", strdup("Infinite loop !"));
        exit (-1);
    }
    else
        carrier->num_lines = strcat(carrier->num_lines, carrier->str_go_to);
}

void    goto_or_print(t_format *carrier)
{
    int i;
    
    i = 0;
        
    if (carrier->temp[0] == 'g')
        loop(carrier);        
    else if (carrier->temp[0] != 'g')
    {
        while (isdigit(carrier->temp[i]) || isblank(carrier->temp[i]))
        {
            carrier->num_lines[i] = carrier->temp[i];
            i++;
        }
        while (carrier->temp[i] != '\0')
        {
            carrier->result[carrier->positioin_result] = carrier->temp[i];
            i++;
            carrier->positioin_result++;
        }
    }
    print_struct(carrier);
}

void	ft_extract(t_format *carrier)
{
	int i;

    i = 0;
    while (carrier->duplicate[carrier->position] != '\n')
	{
        carrier->temp[i] = carrier->duplicate[carrier->position];
        i++;
        carrier->position++;
    }
	carrier->temp[carrier->position] = '\0';
	carrier->position++;
    goto_or_print(carrier);
}

void	chop(t_format *carrier)
{
    while (carrier->position < carrier->len)
        ft_extract(carrier);
    return ;
    
}

char		*ft_goto_parser(const char *code)
{
    t_format    carrier;
    
        
    carrier_init(&carrier);
    carrier.duplicate = strdup(code);
    carrier.len = strlen(carrier.duplicate);
    carrier.duplicate = del_spaces(&carrier);
    chop(&carrier);
    return (carrier.result);
}

/*
int    main()
{
char    *code;

code = (
  "10 Hola\n"
  "goto 30\n"
  "20 se va a\n"
  "goto 50\n"
  "30 esto     20\n"
  "goto 20\n"
  "50     acabar.\n"
  "goto 60\n"
  "60 Y punto     .\n"
);

printf("%s", ft_goto_parser(code));
printf("\n");
system("leaks a.out");
}
*/