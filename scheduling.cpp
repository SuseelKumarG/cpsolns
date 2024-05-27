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
    int h,p;
    cin>>h>>p;
    int cnt=0;
    while((1<<(cnt+1))<p)
    cnt++;
    int ans=((1<<h)-(1<<(cnt+1)))/p;
    ans+=(ans*p!=((1<<h)-(1<<(cnt+1))));
    ans+=cnt+1;
    // int time=rem/p;
    // time += (time*p!=rem);
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
        solve();
    }
    return 0;
}