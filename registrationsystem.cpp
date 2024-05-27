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
    map<string,int>check;
    while(n--)
    {
        string s;
        cin>>s;
        if(check[s])
        cout<<s<<check[s]<<'\n';
        else
        cout<<"OK\n";
        check[s]++;
    }
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