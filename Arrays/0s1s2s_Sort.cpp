#include <iostream>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE    
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        freopen("../error.txt", "w", stderr);
    #endif
    
    int test=1;
    cin>>test;

    while(test--)
    {
        int size;
        cin>>size;

        int arr[size],i,j,cntZero,cntOne,cntTwo;
        cntZero=cntOne=cntTwo=0;

        //Input & Count
        for(i=0; i<size; i++)
        {
            cin>>arr[i];
            if(arr[i] == 0)
                cntZero++;
            else if(arr[i] == 1)
                cntOne++;
            else
                cntTwo++;
        }
        //Assingments
        for(i=0; i<cntZero; i++)
            arr[i]=0;

        for(j=i; cntOne!=0; cntOne--,j++)
            arr[j]=1;  
            
        for(i=j; cntTwo!=0; cntTwo--,i++)
            arr[i]=2;

        //Display Sorted Array
        for(i=0; i<size; i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }

}