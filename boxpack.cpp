#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    map<long long,int>ans;
    while(t--)
    {
        long long n;
        cin>>n;
        ans[n]++;
    }
    int box=0;
    for(auto it:ans)
    {
        box=max(box,it.second);
    }
    cout<<box<<'\n';
}