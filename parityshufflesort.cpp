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
    // int m=n-1;
    if(n==1)
    {
        cout<<0<<'\n';
        return;
    }
    if(n==2)
    {
        cout<<1<<'\n'<<1<<' '<<2<<'\n';
        return;
    }
    if((arr[0]+arr[n-1])&1)
    arr[n-1]=arr[0];
    else
    arr[0]=arr[n-1];
    cout<<n-1<<'\n';
    cout<<1<<' '<<n<<'\n';
    for(int i=1;i<n-1;i++)
    {
        if((arr[0]+arr[i])&1)
        cout<<1<<' '<<i+1<<'\n';
        else
        cout<<i+1<<' '<<n<<'\n';
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    cin>>t;
    while(t--)
    solve();
    return 0;
}