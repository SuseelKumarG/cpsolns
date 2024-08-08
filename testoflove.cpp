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
typedef vector<bool> vb;
#define MAX 998244353
#define N 10    010

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

ll binmul(ll a,ll b)
{
    ll ans=0;
    while(b)
    {
        if(b&1) ans=(ans+a)%MAX;
        a=(a+a)%MAX;
        b>>=1;
    }
}


void solve()
{
    bool poss=1;
    int n,m,k;
    cin>>n>>m>>k;
    string s;
    cin>>s;
    int log=-1;
    if(m>n)
    goto A;
    for(int i=0;i<m;i++)
    if(s[i]=='L')
    log=i;
    if(log==-1)
    log=m-1;
    // cout<<log<<'\n';
    for(int i=log;i<n&&poss;)
    {
        // i--;
        // cout<<0<<' '<<i<<'\n';
        if(s[i]=='L')
        {
            if(i+m>=n)
            goto A;
            for(int j=0;j<=m;j++)
            {
                if(i+j>=n)
                goto A;
                if(s[i+j]=='L')
                log=i+j;
            }
            if(log==i)
            i+=m;
            else
            i=log;
            // if(i!=log)
            // i=log;
        }
        // cout<<1<<' '<<i<<'\n';
        // cout<<i<<' '<<log<<' ';
        // cout<<s[i]<<i<<' '<<log<<' ';
        while(s[i]=='W'&&i<n&&poss)
        {
            if(!k)
            {poss=0;
            break;}
            k--;
            i++;
        }
        // cout<<2<<' '<<i<<'\n';
            // cout<<i<<'\n';
        if(s[i]=='C')
        poss=0;
    }
    A:
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
        // cout<<5%0<<'\n';
        solve();
    }
    return 0;
}