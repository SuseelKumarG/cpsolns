#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>arr(m+1);
    for(int i=0;i<=m;i++)
    cin>>arr[i];
    int check=arr[m];
    int ans=0;
    for(int i=0;i<m;i++)
    {
        int dup=check^arr[i];
        if(__builtin_popcount(dup)<=k)
        ans++;
    }
    cout<<ans;
}