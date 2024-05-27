#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],hsh[100000]={0};
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            hsh[arr[i]]++;
        }
        while(x--)
        {
            int z,count=0;
            cin>>z;
            cout<<hsh[z]<<'\n';
        }
    }
    return 0;
}