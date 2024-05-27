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
    int n;
    cin>>n;
    vvi arr(2);
    vi up(n+1),lo(n+1);
    for(int i=0;i<2;i++)
    {
        vi temp(n+1);
        int sum=0;
        for(int j=1;j<=n;j++)
        {
            cin>>temp[j];
            sum+=temp[j];
            if(i)
            lo[j]=sum;
            else
            up[j]=sum;
        }
        arr[i]=temp;
    }
    int ans=INT_MAX;
    for(int i=1;i<=n;i++)
    {
        int a=up[n]-up[i];
        int b=lo[i-1];
        ans=min(ans,max(a,b));
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