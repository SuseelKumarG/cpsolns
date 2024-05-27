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
        vector<pair<int,int>>arr(n);
        for(int i=0;i<2*n;i++)
        {
            int x;
            cin>>x;
            if(i<n)
            arr[i].first=x;
            else
            arr[i-n].second=x;
        }
        sort(arr.begin(),arr.end());
        int ans=0;
        for(auto it:arr)
        cout<<it.first<<' ';
        cout<<'\n';
        for(auto it:arr)
        cout<<it.second<<' ';
        cout<<'\n';
    }
}