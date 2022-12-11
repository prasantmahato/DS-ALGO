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

/*

    Returns -1 if sub_string is not present
    Return (pos) if sub_string is present

*/
int substr(char s1[],char sub_s[])
{
    int i, start, end;
    i=start=end=0;

    int len = find_len(s1);
    int sub_len = find_len(sub_s);
    int pos = 0;
    int flag = 0;
    for(i=0; i<len; i++)
    {
        for(int j=i,start=0; j<len; j++)
        {
            if(s1[j] == sub_s[start])
            {
                start++;
                pos = j;
            }
            if(start == sub_len)
            {
                flag = 1;
            }
        }
    }
    if(flag == 0)
        return -1;
        
    return pos-1;
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
            int pos = substr(s1.string,sub.string);
            if(pos != -1)
                printf("\nSubstring pos: %d\n",pos);
            else
                printf("\n\'%s\' not present in %s",sub.string, s1.string);
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
