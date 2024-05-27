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
#define eps 0.000000001

void solve()
{
    ll n;
    cin>>n;
    vl arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    ll x=arr[0];
    ll left=x;
    ll leftest=-1;
    ll s=-1,e=-1;
    bool dec=0;
    bool done=0;
    bool poss=1; 
    for(ll i=1;i<n;i++)
    {
        if(arr[i]<x && !done)
        {
            if(!dec)
            s=i;
            e=i+1;
            dec=1;
            if(arr[i]<leftest)
            poss=0;
        }
        if(done)
        dec=0;
        if(dec && arr[i]>x)
        done=1;
        if(done && arr[i]<x)
        poss=0;
        if(arr[i]>left)
            left=arr[i];
        if(!dec)
        {
            if(arr[i]>leftest)
            leftest=arr[i-1];
        }
        if(done && arr[i]<left)
        poss=0;
        x=arr[i];
    }
    if(poss)
    {
        cout<<"yes\n";
        if(s!=-1)
        cout<<s<<' '<<e<<'\n';
        else
        cout<<1<<' '<<1<<'\n';
    }
    else
    cout<<"no\n";
    // cout<<leftest<<'\n';
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    // cin>>t;
    while(t--)
    solve();
    return 0;
}