#include<stdio.h>
#include<string.h>

int compare(const char *a, const char *b)
{
    while(*a && *b)
    {
        if(*a != *b)
            return 0;
        a++;
        b++;
    }
    return(*b == '\0');
}

char *sub_str(const char *str, const char *sub)
{
    while(*str)
    {
        if((*str == *sub) && (compare(str,sub)))
            return str;
        
        str++;
    }
    return NULL;
}


int main()
{
    char str[] = "Merry Chirstmas";
    char sub[] = "santa";

    char *pos = sub_str(str,sub);
    int index;
    if(pos!= NULL)
    {
        index = pos-str;
        printf("\nThe substring %s was found at index %d\n",sub,index);
    }
    else
        printf("\nThe substring '%s' was not found in the string '%s' \n",sub,str);

    // const char res = sub_str(str,sub);
    // printf("%s\n",str);
    // printf("%s\n",sub_str(str,sub));
   
    return 0;

}
