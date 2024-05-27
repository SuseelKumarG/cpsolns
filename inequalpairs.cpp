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
typedef vector<bool> vb;
#define MAX 1000000007

void solve()
{
    int n;
    cin>>n;
    vi arr(n+1),check;   
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        if(arr[i]<i)
        check.push_back(i);
    }
    int m=check.size()-1;
    ll ans=0;
    if(m)
    for(int i=m;i>0;i--)
    {
        int x=arr[check[i]];
        int a=0,b=i;
        while(a<b)
        {
            int c=a+(b-a)/2;
            if(check[c]<x)
                a=c+1;
            else
                b=c;
        }
        ans+=a;
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
    {
        solve();
    }
    return 0;
}