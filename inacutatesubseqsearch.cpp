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
    int n,m,k;
    cin>>n>>m>>k;
    vi a(n),b(m);
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<m;i++)
    cin>>b[i];
    unordered_map<int,int> x,y,z;
    for(int i=0;i<m;i++)
    x[b[i]]++;
    int cnt=0;
    int ans=0;
    for(int i=0;i<m;i++)
    {
        if(x.find(a[i])!=x.end())
        {
            if(y[a[i]]<x[a[i]])
            {
                y[a[i]]++;
                cnt++;
            }
            else
            z[a[i]]++;
        }
    }
    if(cnt>=k)
    ans++;
    for(int i=0;i<n-m;i++)
    {
        if(x.find(a[i])!=x.end())
        {
            if(z[a[i]])
            {
                z[a[i]]--;
            }
            else if(y[a[i]])
            {
                y[a[i]]--;
                cnt--;
            }
        }
        if(x.find(a[i+m])!=x.end())
        {
            if(y[a[i+m]]<x[a[i+m]])
            {
                y[a[i+m]]++;
                cnt++;
            }
            else
            z[a[i+m]]++;
        }
        if(cnt>=k)
        ans++;
    }
    cout<<ans<<'\n';
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