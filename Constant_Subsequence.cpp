#include <bits/stdc++.h>
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
    int si;
    cin>>si;
    vi b(si);
    for(auto &it:b)
    cin>>it;
    vi p,n;
    for(auto it:b)
    {
        if(it<0)
        n.push_back(it);
        else
        p.push_back(it);
    }
    vi a(si);
    int temp=1;
    reverse(p.begin(),p.end());
    reverse(n.begin(),n.end());
    while(!p.empty()&&!n.empty())
    {
        if(temp&1)
        {int x=p.back();
            a.push_back(x);
            p.pop_back();
        }
        else
        {
            int x=n.back();
            a.push_back(x);
            n.pop_back();
        }
        temp++;
    }
    while(!p.empty())
    {int x=p.back();
            a.push_back(x);
            temp++;
        p.pop_back();
    }
    while(!n.empty())
    {
        int x=n.back();
        a.push_back(x);
        temp++;
        n.pop_back();
    }
    reverse(a.begin(),a.end());
    int curr=0,maxm=0;
    for(int i=0;i<si;i++)
    {
        curr+=a[i];
        maxm=max(maxm,curr);
        if(curr<0)
        curr=0;
    }
    cout<<maxm<<'\n';
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}