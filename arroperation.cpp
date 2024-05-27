#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int>arr(n);
        for(int i=0;i<n;i++)
        cin>>arr[i];
        sort(arr.begin(),arr.end());
        reverse(arr.begin(),arr.end());
        int ans=0;
        for(int i=2*k;i<n;i++)
        ans+=arr[i];
        for(int i=0;i<k;i++)
        {
            ans+=arr[i+k]/arr[i];
        }
        cout<<ans<<'\n';
    }
}