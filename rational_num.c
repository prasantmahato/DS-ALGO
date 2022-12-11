#include <stdio.h>
#include <stdlib.h>

typedef struct rational{
    int nmtr;  // Numerator of the rational number
    int dnmtr;  // Denomator of the rational number
}rational;

struct rational ADD(rational n1, rational n2)
{
    rational res;
    
    /*
        add of (a/b + c/d)  = (a*d*b + c*b*d) / (b*d)
        
    */
    
    res.nmtr = (n1.nmtr * n2.dnmtr) + (n2.nmtr * n1.dnmtr);
    res.dnmtr = n1.dnmtr * n2.dnmtr;
    
    return res;
}

struct rational SUB(rational n1, rational n2)
{
    rational res;
    
    /*
        DIFF of (a/b - c/d)  = (a*d*b - c*b*d) / (b*d)
        
    */
    
    res.nmtr = (n1.nmtr * n2.dnmtr) - (n2.nmtr * n1.dnmtr);
    res.dnmtr = n1.dnmtr * n2.dnmtr;
    
    return res;
}


struct rational MUL(rational n1, rational n2)
{
    rational res;
    
    /*
        PRODUCT of (a/b - c/d)  = (a*b) / (c*d)
        
    */
    
    res.nmtr = (n1.nmtr * n2.nmtr);
    res.dnmtr = (n1.dnmtr * n2.dnmtr);
    
    return res;
}

/* 
    Function to check if two rational number are equal 
    Returns 1 if they are equal
        else 0
*/
int checkEqual(rational n1, rational n2)
{
    int isEqual=1;
    
    if(n1.nmtr * n2.dnmtr == n1.dnmtr * n2.nmtr)
        isEqual = 1;
    else
        isEqual = 0;
        
    return isEqual;
    
}



int main()
{
    rational num[2], result;
    
    for(int i=0; i<2; i++)
    {
        
        printf("Enter numerator of the rational number%d: ",i+1);
        scanf("%d",&num[i].nmtr);
    
        printf("Enter denomator of the rational number%d: ",i+1);
        scanf("%d",&num[i].dnmtr);
        
        printf("\n");
    
        if(num[i].dnmtr == 0)
        {
            printf("\nError(): Denomator cannot be zero.");
            exit(-1);
        }
    
    }
    
    printf("\n");
    result = ADD(num[0], num[1]);
    printf("SUM: %d / %d\n",result.nmtr,result.dnmtr);
    
    result = SUB(num[0], num[1]);
    printf("DIFF: %d / %d\n",result.nmtr,result.dnmtr);
    
    result = MUL(num[0], num[1]);
    printf("PRODUCT: %d / %d\n",result.nmtr,result.dnmtr);
    
    int status = checkEqual(num[0], num[1]);
    
    if(status == 1)
        printf("\nBoth rational numbers are equal.!!");
    else
        printf("\nNumbers not equal.!!");
    
    
    return 0;
    
}