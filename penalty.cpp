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
    string s;
    cin>>s;
    int n=10;
    int sa=0,sb=0,ca=0,cb=0;
    for(int i=0;i<10;i++)
    {
        if(i&1)
        {
            if(s[i]=='1')
            sb++;
            if(s[i]=='?')
            cb++;
        }
        else{
            if(s[i]=='1')
            sa++;
            if(s[i]=='?')
            ca++;
        }
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