#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++)
        cin>>arr[i];
        vector<int>ans(n);
        ans[0]=0;
        for(int i=0;i<n-1;i++)
        {
            int xo=arr[i]^arr[i+1];
            xo&=arr[i];
            ans[i+1]=xo;
            arr[i+1]^=xo;
        }
        for(auto it:ans)
        cout<<it<<' ';
        cout<<'\n';
    }
    
}
