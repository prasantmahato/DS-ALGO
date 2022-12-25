#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct STRING{
    char string[MAX_SIZE];
}STRING;

int find_len(char str[])
{
    int i=0;
    for(i=0; str[i]!='\0'; i++);
    return i;
}

/*
    returns 0 if both are same
    returns 1 if len(s1) > len(s2) or s1 != s2
    returns -1 if len(s1) < len(s2)
*/ 
int compare(char s1[], char s2[])
{
    int len1 = find_len(s1);
    int len2 = find_len(s2);

    if (len1 < len2)
        return -1;
    else if(len1 > len2)
        return 1;
    else
    {
        for(int i=0; i<len1; i++)
        {
            if (s1[i] != s2[i])
                return 1;
        }
        return 0;
    }
}


void concat(char s1[], char s2[])
{
    char res[MAX_SIZE];
    int i=0,j=0;
    while(s1[i]!='\0')
    {
        res[j] = s1[i];
        i++;
        j++;
    }
    i=0;
    while(s2[i]!='\0')
    {
        res[j] = s2[i];
        i++;
        j++;
    }
    res[j] = '\0';
    printf("\n%s\n",res);
}

int cmp(const char *a, const char *b)
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

// Return the starting address of the substring if found
char *sub_str(const char *str, const char *sub)
{
    while(*str)
    {
        if((*str == *sub) && (cmp(str,sub)))
            return str;
        
        str++;
    }
    return NULL;
}

int main()
{
    STRING s1,s2,sub;

    printf("\nEnter the string1: ");
    scanf("%s",s1.string);
    
    printf("\nEnter the string2: ");
    scanf("%s",s2.string);

    int choice = 0;
    do
    {
        printf("\n0. Exit");
        printf("\n1. Length of strings.");
        printf("\n2. Equality check.");
        printf("\n3. Find Substring.");
        printf("\n4. Concatinate strings.");
        printf("\nChoose an option: ");
        scanf("%d",&choice);
        printf("\n");

        switch (choice)
        {
            
        case 1:
            printf("Length(STRING 1): %d\n",find_len(s1.string));
            printf("Length(STRING 2): %d\n",find_len(s2.string));
            break;

        case 2:
            if(compare(s1.string,s2.string) == 0)
                printf("Equal\n");
            else
                printf("Not Equal\n");
            break;
        
        case 3:
            printf("\nEnter sub-string to find in STRING1: ");
            scanf("%s",sub.string);
            char *position = sub_str(s1.string, sub.string);

            // If position is not null
            if(position)
            {
                int index = position - s1.string;
                printf("\nThe substring '%s' was found at index %d\n",sub.string,index);
            }
            else
                printf("\nThe substring '%s' was not found in '%s'\n",sub.string,s1.string);
            break;
        case 4:
            concat(s1.string,s2.string);
            break;

        default:
            break;
        }
    } while (choice != 0);
    
    return 0;
}
