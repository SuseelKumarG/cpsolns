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

bool poss(int mid,vl &a)
{

}

void solve()
{
    ll n,maxm;
    cin>>n>>maxm;
    vl a(n);
    for(auto &it:a)
    cin>>it;
    ll maax=1LL<<n;
    vll dp(maax);
    dp[0]={1,0};
    for(ll i=1;i<(maax);i++)
    {
        pll w={LLONG_MAX,LLONG_MAX};
        int j=0;
        ll x=i;
        while(x)
        {
            if(((1<<j)&i))
            {
                pll temp=dp[(1<<j)^i];
                if(temp.second+a[j]<=maxm)
                temp.second+=a[j];
                else
                {
                    temp.first+=1;
                    temp.second=a[j];
                }
                w=min(w,temp);
            }
            x>>=1;
            j++;
        }
        dp[i]=w;
    }
    cout<<dp[maax-1].first<<'\n';
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