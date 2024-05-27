#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    map<string,int>ans;
    while(n--)
    {
        string s;
        cin>>s;
        ans[s]++;
        if(ans[s]>1)
        cout<<"YES\n";
        else
        cout<<"NO\n";
    }
}