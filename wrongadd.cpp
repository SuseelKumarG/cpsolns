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
    ll a,b;
    cin>>a>>b;
    vector<int>ans;
    while(b)
    {
        int x=a%10;
        int y=b%10;
        if(y<x)
        {
            b/=10;
            y+=10*(b%10);
            if(y>=x && y>=10 && y<=19)
            ans.push_back(y-x);
            else{
                cout<<-1<<'\n';
                return;
            }
        }
        else
        ans.push_back(y-x);
        a/=10;
        b/=10;
    }
    if(a)
    {
        cout<<-1<<'\n';
        return;
    }
    else
    {
        while (ans.back() == 0) ans.pop_back();
        reverse(ans.begin(),ans.end());
        for(auto it:ans)
            cout<<it;
        cout<<'\n';
    }
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