#include<stdio.h>

#define max 100

void saddle_point(int arr[max][max],int n)
{
    int i,j;
    i=j=0;
    for(i=0; i<n; i++)
    {
        int min_row = arr[i][0], col_ind = 0;
        for(j=1; j<n; j++)
        {
            if(min_row > arr[i][j])
            {
                min_row = arr[i][j];
                col_ind = j;
            }
        }

        int k=0;
        for(k=0; k<n; k++)
        {
            if(min_row < arr[k][col_ind])
                break;
        }
        if(k==n)
        {
            printf("\nSaddle point value: %d",min_row);
            return;
        }
    }
    printf("\nThere is no saddle point in this matrix.");   
    return;
}
int main()
{
    int mat[max][max]={
        {0,1,0},
        {-2,4,-1},
        {0,3,0}
    };
    int n = 3;
    saddle_point(mat,n);
    return 0;
}

