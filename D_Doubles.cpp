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
    ll n;
    cin>>n;
    vl k(n);
    vector<map<ll,ll>> hsh(n);
    for(ll i=0;i<n;i++)
    {
        cin>>k[i];
        for(ll j=0;j<k[i];j++)
        {
            ll x;
            cin>>x;
            hsh[i][x]++;
        }
    }
    ll ans=0;
    ll div=1;
    for(ll i=0;i<n;i++)
    {
        for(ll j=i+1;j<n;j++)
        {
            ll curr=0;
            if(hsh[i].size()<hsh[j].size())
            {
                for(auto it:hsh[i])
                {
                    curr+=it.second*hsh[j][it.first];
                }    
            }
            else
            {   
                for(auto it:hsh[j])
                {
                    curr+=it.second*hsh[i][it.first];
                }
            }
            if((ans/(div*1.0))<(curr/(k[i]*k[j]*1.0)))
            {
                ans=curr;
                div=k[i]*k[j];
            }
        }
    }
    cout<<setprecision(9)<<(ans/(div*1.0))<<'\n';
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