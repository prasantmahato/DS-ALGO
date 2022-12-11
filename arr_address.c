#include <stdio.h>

// typedef enum datatype { CHAR=1, INT=2, FLOAT=4, DOUBLE=8};

void print_arr(int arr[], int size)
{
    for(int i=0; i<size; i++)
        printf("%d\t",arr[i]);
}

int main()
{
    int dimension,base_addr;
    printf("\nEnter base address: ");
    scanf("%d",&base_addr);

    int dt=0;
    printf("\nEnter sizeof(datatype)-> (CHAR(1),INT(2),FLOAT(4),DOUBLE(8)): ");
    scanf("%d",&dt);


    // printf("Datatype Size: %d\n",dt);

    printf("\nEnter array dimension: ");
    scanf("%d",&dimension);

    int src[dimension],dest[dimension],i=0;
    printf("\nEnter dimension sizes for source array.");
    for(i=0; i<dimension; i++)
    {
        printf("\nDimension %d: ",i+1);
        scanf("%d",&src[i]);
    }
    printf("\nEnter dimension sizes for array which address need to be calculated.");
    for(i=0; i<dimension; i++)
    {
        printf("\nDimension %d: ",i+1);
        scanf("%d",&dest[i]);
    }
    // print_arr(src,dimension);
    // print_arr(dest,dimension);

    long int address=0,tmp=1;
    for(int i=0; i<dimension; i++)
    {
        tmp *= dest[i];
        // printf("%d *",src[i]);
        for(int j=i+1; j<dimension; j++)
        {
            tmp *= src[j];
            // printf("%d * ",dest[j]);
        }
        // printf("\n");

        address += tmp;
        tmp=1;
        // printf("\n Sum: %ld",address);
    }
    address *= dt;
    address += base_addr;
    

    printf("\nThe destination array address is: %ld\n",address);


    return 0;
}