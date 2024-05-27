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
    int n;
    cin>>n;
    ll x;
    map<ll,ll>check;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        x%=10;
        if(check[x]<3)
        check[x]++;
    }
    bool poss=0;
    vi arr;
    for(auto it:check)
    {
        int a=it.first,b=it.second;
        for(int i=0;i<b;i++)
        arr.push_back(a);
    }
    for(int i=0;i<arr.size();i++)
    {
        for(int j=i+1;j<arr.size();j++)
        {
            for(int k=j+1;k<arr.size();k++)
            {
                if((arr[i]+arr[j]+arr[k])%10==3)
                {
                    poss=1;
                    // cout<<i<<' '<<j<<' '<<k<<'\n';
                    break;
                }
            }
        }
    }
    cout<<(poss?"YES":"NO")<<'\n';
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