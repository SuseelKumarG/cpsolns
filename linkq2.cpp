#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl; 
typedef vector<pll> vll; 
typedef vector<bool> vb;
#define MAX 1000000007
#define N 10010

long long gcdl(long long a, long long b){
    while(a > 0 && b > 0){
        if(a > b){
            a %= b;
        }
        else{
            b %= a;
        }
    }
    return a + b;
}  
ll lcml(ll a,ll b)
{
    a=(a*b)/gcdl(a,b);
    return a;
}
int gcd(int a, int b){
    while(a > 0 && b > 0){
        if(a > b){
            a %= b;
        }
        else{
            b %= a;
        }
    }
    return a + b;
}
int lcml(int a,int b)
{
    a=(a*b)/gcd(a,b);
    return a;
}

void solve()
{
    // dunno what is n here
    string s;
    cin>>s;
    int n=s.size();
    vi col(3);
    ll mul=1;
    for(int i=7;i>=0;i--)
    {
        if(s[i]=='1')
        col[0]+=mul;
        mul*=2;
    }
    mul=1;
    for(int i=15;i>=8;i--)
    {
        if(s[i]=='1')
        col[1]+=mul;
        mul*=2;
    }
    mul=1;
    for(int i=23;i>=16;i--)
    {
        if(s[i]=='1')
        col[2]+=mul;
        mul*=2;
    }
    map<int,string>rep;
    rep[0]="Black";
    rep[1]="Whilte";
    rep[2]="Red";
    rep[3]="Green";
    rep[4]="Blue";
    vvi val(4);
    val[0]={0,0,0};
    val[1]={255,255,255};
    val[2]={255,0,0};
    val[3]={0,255,0};
    val[4]={0,0,255};
    bool mul=0;
    pll ans={LLONG_MAX,-1};
    for(int j=0;j<4;j++)
    {
        ll dist=0;
        for(int i=0;i<3;j++)
        {
            ll curr=col[i]-val[j][i];
            curr*=curr;
            dist+=curr;
        }
        if(dist<ans.first)
        {
            ans={dist,j};
            mul=0;
        }
    }
    if(mul)
    cout<<"AMBIGUOUS\n";
    else
    cout<<rep[ans.second]<<'\n';
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