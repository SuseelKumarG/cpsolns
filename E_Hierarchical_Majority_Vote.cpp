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

ll binexp(ll a,ll b)
{
    ll ans=1;
    while (b)
    {
        if(b&1)
        ans=(ans*a)%MAX;
        b>>=1;
        a=(a*a)%MAX;
    }
    return ans;
}

priority_queue<ll>z,o;
void solve()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll zer=0;
    ll tot=s.length();
    ll win=tot/6+1;
    for(int i=0;i<tot;i+=3)
    {
        int curr=0;
        for(int j=0;j<3;j++)
        {
            if(s[i+j]=='0')
            curr++;
        }
        if(curr>1)
        {
            zer++;
            int ins;
            if(curr==2)
            ins=1;
            else
            ins=2;
            if(o.size()>win)
            {
                if(o.top()>ins)
                {
                    o.pop();
                    o.push(ins);
                }
            }
            else
            o.push(ins);
        }
        else
        {
            int ins;
            if(curr==1)
            ins=1;
            else
            ins=2;
            if(z.size()>win)
            {
                if(z.top()>ins)
                {
                    z.pop();
                    z.push(ins);
                }
            }
            else
            z.push(ins);
        }
    }
    vi hope;
    ll fin=1;
    if(zer>(tot/6))
    fin=0;
    ll need;
    if(fin==1)
    {
        need=win-zer;
        while(!z.empty())
        {
            hope.push_back(z.top());
            z.pop();
        }
    }
    else
    {
        ll one=tot/3-zer;
        need=win-one;
        while(!o.empty())
        {
            hope.push_back(o.top());
            o.pop();
        }
    }
    cout<<accumulate(hope.begin(),hope.begin()+need,0LL);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    while(t--)
    {
        solve();
    }
    return 0;
}