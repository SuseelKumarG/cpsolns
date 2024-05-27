#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<string,int>ans;
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        if(ans[s]==0)
        cout<<"OK\n";
        else
        cout<<s<<ans[s]<<'\n';
        ans[s]++;
    }
}