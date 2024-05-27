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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n;
    cin>>n>>t;
    vl vec[n],ans;
    while(t--)
    {
        ll a,b,c,lastanswer=0;
        cin>>a>>b>>c;
        if(a==1)
        {
            ll idx=(b^lastanswer)%n;
            vec[idx].push_back(c);
        }
        else if(a==2){
        ll idx=(b^lastanswer)%n;
        lastanswer=vec[idx][c%sizeof(vec[idx])];
        cout<<lastanswer<<'\n';
        ans.push_back(lastanswer);
        }
    }
    for(auto it:ans)
    {
        cout<<it<<'\n';
    }
    return 0;
}