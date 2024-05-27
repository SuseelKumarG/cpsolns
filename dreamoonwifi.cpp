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

unordered_map<int,int>check;

void soln(int n,string &s)
{
    if(s.size()==n)
    {
        int score=0;
        for(auto it:s)
        {
            if(it=='+')
            score++;
            else
            score--;
        }
        check[score]++;
        return;
    }
    s.push_back('+');
    soln(n,s);
    s.pop_back();
    s.push_back('-');
    soln(n,s);
    s.pop_back();
}

void solve()
{
    string o,r;
    cin>>o>>r;
    int dest=0,curr=0,unknown=0;
    for(auto it:o)
    {
        if(it=='+')
        dest++;
        else 
        dest--;
    }
    for(auto it:r)
    {
        if(it=='?')
        unknown++;
        else if(it=='+')
        curr++;
        else
        curr--;
    }
    double ans=0;
    if(!unknown)
    {
        if(dest==curr)
        {
            ans=1;
            cout<<setprecision(10)<<ans<<'\n';
            return;
        }
        else{
            cout<<setprecision(10)<<ans<<'\n';
            return;
        }
    }
    if(abs(dest-curr)>unknown || (dest == curr && (unknown & 1)))
    {
        cout<<setprecision(10)<<ans<<'\n';
        return;
    }
    int dist=abs(dest-curr);
    double poss=(1<<unknown);
    string s;
    soln(unknown,s);
    ans=check[dist]/poss;
    cout<<setprecision(10)<<ans<<'\n';
    return;
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