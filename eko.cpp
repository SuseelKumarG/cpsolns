#include<bits/stdc++.h>
using namespace std;
long long n,m;
const long long cnt=1e6+10;
int arr[cnt];
bool sufficient(int mid);
int main()
{
    cin>>n>>m;
    long long max=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(max<arr[i])
        max=arr[i];
    }
    long long hi=max,lo=0,mid;
    while(hi-lo>1)
    {
        mid=(hi+lo)/2;
        if(sufficient(mid))
        lo=mid;
        else
        hi=mid-1;
    }
    if(sufficient(hi))
    cout<<hi<<'\n';
    else
    cout<<lo<<'\n';
}
bool sufficient(int mid)
{
    long long count=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>mid)
        count+=(arr[i]-mid);
    }
    return (count>=m);
}
