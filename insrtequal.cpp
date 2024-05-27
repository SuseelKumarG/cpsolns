#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000007
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n;
        cin>>n;
        long long arr[n],gd=0,x,ans=0,temp=0;
        for(int i=0;i<n;i++)
        cin>>arr[i];
        if(n==1)
        {
            cout<<1<<'\n';
            continue;
        }
        sort(arr,arr+n);
        for(int i=0;i<n;i++)
        gd=__gcd(gd,arr[n-1]-arr[i]);
        for(int i=0;i<n;i++)
        {
            ans+=(arr[n-1]-arr[i])/gd;
        }
        x=arr[n-1];
        for(int i=n-1;i>=0;i--)
        {
            if(x-temp*gd==arr[i])
            temp++;
            else
            break;
        }
        cout<<ans+temp<<'\n';
    }
}