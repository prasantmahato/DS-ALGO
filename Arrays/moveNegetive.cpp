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
        int size,i;
        cin>>size;
        int arr[size],countNeg=0;

        for(i=0; i<size; i++)
        {    
            cin>>arr[i];
            if(arr[i] < 0)
                countNeg++;
        }
        
        for(int i=0; i<size; i++)
            cout<<arr[i]<<" ";

        cout<<endl;

        int pos = size-countNeg;
        int negArr[countNeg], posArr[pos];

        for(int j=0,i=0,k=0; i<size; i++)
        {
            if(arr[i] < 0)
            {
                negArr[j] = arr[i];
                j++;
            }
            else
            {
                posArr[k] = arr[i];
                k++;
            }
        }
        
        for(i=0; i<countNeg; i++)
        {
            cout<<negArr[i]<<"\n";
            arr[i]=negArr[i];
        }
        for(int j=i,k=0; pos>0; pos--)
        {
            cout<<posArr[k]<<"\n";
            arr[j]=posArr[k];
            k++;
        }
        

        for(int i=0; i<size; i++)
            cout<<arr[i]<<" ";
    }
}