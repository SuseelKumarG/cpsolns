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
    string s;
    cin>>s;
    int two=0,three=0;
    ll tot=0;
    for(auto it:s)
    {
        tot+=it-'0';
        if(it=='2')
        two++;
        if(it=='3')
        three++;
    }
    int rem=tot%9;
    int x=10000000;
    int y=10000000;
    for(int i=1;i<=100000;i++)
    {
        if((6*i+rem)%9==0)
        {
            x=i;
            break;
        }
    }
    for(int i=1;i<=100000;i++)
    {
        if((2*i+rem)%9==0)
        {
            y=i;
            break;
        }
    }
    // cout<<rem<<' ';
    if(rem==0)
    {
        x=0;
        y=0;
    }
    bool poss=0;
    if(x>three)
    {
        if(two>=3*(x-three))
        poss=1;
    }
    else
    poss=1;
    if(y>two)
    {
        if((three>=(y-two)/3)&&!((y-two)%3))
        {
            // cout<<1<<'\n';
            poss=1;}
        if((three>=(y-two+1)/3)&&!((y-two+1)%3)&&two>=1)
            {// {cout<<2<<'\n';
        poss=1;}
        if((three>=(y-two+2)/3)&&!((y-two+2)%3)&&two>=2)
            {// {cout<<3<<'\n';
        poss=1;}
    }
    else
    poss=1;
    // cout<<x<<' '<<y<<'\n';
    cout<<(poss?"YES":"NO")<<'\n';
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