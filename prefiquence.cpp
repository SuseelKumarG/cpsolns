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
    string a,b;
    cin>>a>>b;
    queue<char>check;
    for(int i=0;i<m;i++)
    check.push(a[i]);
    for(int i=0;i<m;i++)
    {
        if(b[i]==check.front())
        check.pop();
    }
    cout<<m-check.size()<<'\n';
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