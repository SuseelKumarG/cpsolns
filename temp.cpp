#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr1[n],arr2[n];
    for(int i=0;i<2*n;i++)
    {
        if(i<n)
        cin>>arr1[i];
        else
        cin>>arr2[i-n];
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr1[i]<<' '<<arr2[i]<<'\n';
    }
}