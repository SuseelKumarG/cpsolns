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

ll find(vl &a,ll n)
{
    int s=0,e=a.size()-1;
    while(e-s>1)
    {
        int m=(e+s)>>1;
        if(a[m]<n && a[m+1]>n)
        return m;
        if(a[m]<n)
        s=m+1;
        else
        e=m;
    }
    if(a[e]==n)
    return e;
    else
    return s; 
}

void solve()
{
    ll n,k,q;
    cin>>n>>k>>q;
    vl a(k+1),b(k+1);
    a[0]=0,b[0]=0;
    for(int i=1;i<=k;i++)
    cin>>a[i];
    for(int i=1;i<=k;i++)
    cin>>b[i];
    while(q--)
    {
        ll x;
        cin>>x;
        int ind=find(a,x);
        if(a[ind]==x)
        {
            cout<<b[ind]<<'\n';
            continue;
        }
        int ans=b[ind]+(x-a[ind])*(b[ind+1]-b[ind])/(a[ind+1]-a[ind]);
        cout<<ans<<' ';
    }
    cout<<'\n';
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