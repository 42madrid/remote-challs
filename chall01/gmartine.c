int hv_necklace(char *s1, char *s2)
{
    int i;
    int j;
    int aux;
    int size;
    int flag;

    aux = -1;
    i = 0;
    while (1 == 1)
    {
        flag = 0;
        i = aux + 1;
        while(s2[i] != '\0' && flag == 0)
        {
         if(s1[0] == s2[i])
             flag=1;
            else
             i++;
        }
        if(flag == 0 && !(s2[0] == '\0' && s1[0] == '\0'))
            return(0);
        else if((s2[0] == '\0' && s1[0] == '\0'))
            return (1);
        aux = i;
        flag = 0;
        size = -1;
        j  = 0;
        while (s1[j] != '\0' && flag == 0)
        {
            if(s1[j] != s2[i])
                flag = 1;
            j++;
            i++;
            if (s2[i] == '\0')
            {
                size = i;
                i = 0;
            }
        }
        if(!(flag == 1 || size != j))
            return (1);
    }
    return (0);
}