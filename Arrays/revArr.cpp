#include <iostream>
using namespace std;

int revArr(int size,char *arr)
{
    char temp[size];
    int i=0,j=size;

    for(i=0,j=size-1; i<size; i++,j--)
    {
        temp[i]= arr[j];
    }
    for(i=0; i<size; i++)
        arr[i]=temp[i];

}

int revArr(char *arr, int start, int end)
{
    while(start < end)
    {
        char temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("../input.txt","r", stdin);
        freopen("../output.txt", "w", stdout);
        freopen("../error.txt", "w", stderr);
    #endif

    int size;
    cin>>size;

    char arr[size];
    for(int i=0; i<size; i++)
        cin>>arr[i];

    //Display Original Array        
    cout<<"Original Array: ";        
    for(int i=0; i<size; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    //Reversed Array which uses extra space        
    cout<<"\nReverse Method 1: ";
    revArr(size,arr);
    for(int i=0; i<size; i++)
        cout<<arr[i]<<" ";

    //Reversed Array which is done in O(n) time.
    cout<<"\nReverse Method 2: ";
    revArr(arr,0,size-1);
    for(int i=0; i<size; i++)
        cout<<arr[i]<<" ";

    
}