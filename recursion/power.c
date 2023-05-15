#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int power(int n,int x)
{
    if(x == 1)
        return n;
    return power(n*n,x-1);
}


char *strrev(char *str)
{
    int l = strlen(str);
    int mid = l/2;
    char tmp;
    int i=0,j = l-1;
    for(int i=0, j=l-1; i<=mid; i++,j--)
    {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
    return str;
}


int main()
{
    printf("%d\n",power(5,2));

    printf("\nEnter a string: ");
    size_t buff_size=100;
    size_t characters;
    char *buffer = (char *)malloc(buff_size * sizeof(char));
    characters = getline(&buffer, &buff_size, stdin);
    printf("\nCharacters typed: %zu\n",characters);
    printf("Reversed: %s\n",strrev(buffer));
    
    return 0;
}