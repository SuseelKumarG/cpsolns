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
const int N=1000005;
vl arr(N);

void seive()
{
    for(int i=2;i<=N;i++)
    {
        if(!arr[i])
        {
            for(int j=2*i;j<=N;j+=i)
            {
                if(!arr[j])
                arr[j]=i;
            }
            arr[i]=i;
        }
    }
}

void solve()
{
    ll n,m;
    cin>>n>>m;
    if(n==1)
    {
        cout<<"YES\n";
        return;
    }
    // cout<<arr[674677]<<'\n';
    cout<<((arr[n]>m)?"YES":"NO")<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    seive();
    ll t=1;
    cin>>t;
    while(t--)
    solve();
    return 0;
}