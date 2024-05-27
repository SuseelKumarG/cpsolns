#include<bits/stdc++.h>
using namespace std;
int n,m;
const int cnt=1e6;
long long arr[cnt];
bool iscow[cnt];
bool isposs(int mid);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        int hi=arr[n-1]-arr[0],lo=1,mid;
        while (hi-lo>1)
        {
            mid=lo+(hi-lo)/2;
            if(isposs(mid))
            lo=mid;
            else
            hi=mid-1;
        }
        if(isposs(hi))
        cout<<hi<<'\n';
        else
        cout<<lo<<'\n';
    }
}
bool isposs(int mid)
{
    int cow=m-1,ind=0;
    for(int i=1;i<n;i++)
    {
        if(arr[i]-arr[ind]>=mid)
        {
            ind=i;
            cow--;
        }
        if(!cow)
        break;
    }
    return !cow;
}