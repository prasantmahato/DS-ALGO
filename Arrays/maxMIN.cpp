#include <iostream>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE 
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        freopen("../error.txt", "w", stderr);
    #endif

    int size;
    cin>>size;

    int arr[size],i=0;
    for(i=0; i<size; i++)
        cin>>arr[i];

    int max=arr[0];
    int min=arr[0];
    for(i=0; i<size; i++)
    {
        if(arr[i] > max)
            max = arr[i];
        if(arr[i] < min)
            min = arr[i];
    }
    cout<<"Max: "<<max<<"\tMin: "<<min;
}