#include <bits/stdc++.h>
// #include <iostream>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl; 
#define MAX 1000000007



void solve()
{
    // cout<<1<<'\n';
    string s;
    cin>>s;
    ll n=s.length();
    int ans=INT_MAX;
    vi cnt(26);
    for(int i=0;i<n;i++)
    cnt[s[i]-'a']++;
    for(int i=0;i<26;i++)
    {
        if(cnt[i])
        {
            int curr=0,x=cnt[i];
            for(int j=0;j<x;j++)
            {
                curr+=(s[j]==i+'a');
            }
            ans=min(ans,x-curr);
            for(int j=x;j<n;j++)
            {
                curr+=(s[j]==i+'a');
                curr-=(s[j-x]==i+'a');
                ans=min(ans,x-curr);
            }
        }
    }
    cout<<ans<<'\n';
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        // cout<<1<<'\n';
        solve();
    }
    return 0;
}