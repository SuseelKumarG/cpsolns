#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,temp;
        cin>>n;
        vector<int>arr(n);
        long long count=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            arr[i]-=i;
        }
        map<int,long long>ans;
        for(int i=0;i<n;i++)
        {
            int it=arr[i];
            ans[it]++;
        }
        for(auto it:ans)
        {
            count+=(it.second-1)*it.second/2;
        }
        cout<<count<<'\n';
    }
}