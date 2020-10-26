#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE 
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        freopen("../error.txt", "w", stderr);
    #endif
    
    int test;
    cin>>test;
    while(test--)
    {
        int size=0;
        cin>>size;

        int arr[size];
        for(int i=0; i<size; i++)
            cin>>arr[i];

        int nth=0;  cin>>nth;
        
        sort(arr, arr+size);
        
        cout<<arr[nth-1]<<endl;
        
    }

}