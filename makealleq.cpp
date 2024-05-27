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
    char ch;
    cin>>n>>ch;
    string s;
    cin>>s;
    vector<int>arr;
    int poss=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]!=ch)
        {
            arr.push_back(i);
        }
        else if(i+1>n/2)
        poss=i+1;
    }
    if(arr.empty())
    {
        cout<<0<<'\n';
    }
    else if(poss)
    {
        cout<<1<<'\n';
        cout<<poss<<'\n';
    }
    else
    {
        cout<<2<<'\n';
        cout<<n<<' '<<n-1<<'\n';
    }
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}