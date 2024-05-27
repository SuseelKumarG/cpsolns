#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int max=INT_MIN;
        vector<int>arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            if(max<arr[i])
            max=arr[i];
        }
        for(int i=0;i<n;i++)
        {
            arr[i]=max-arr[i];
        }
        int gc=0;
        for(int i=0;i<n;i++)
        gc=__gcd(gc,arr[i]);
        if(gc)
        cout<<gc<<'\n';
        else
        cout<<-1<<'\n'; 
    }
}