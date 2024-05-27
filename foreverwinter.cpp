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
    int n,m;
    cin>>n>>m;
    vi arr(n+1,0);
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        arr[b]++;
        arr[a]++;
    }
    int a,b;
    vi temp=arr;
    sort(temp.begin(),temp.end());
    for(int i=1;i<=n;i++)
    {
        if(temp[i]!=1)
        {
            if(temp[i]!=temp[i+1])
            {
                a=temp[i];
                b=temp[i+1];
            }
            else
            {
                b=temp[i];
                a=temp[n];
            }
            break;
        }
    }
    cout<<a<<' '<<b-1<<'\n';
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