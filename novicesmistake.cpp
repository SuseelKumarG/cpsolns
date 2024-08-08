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

string str(int n)
{
    string s;
    while(n)
    s.push_back(n%10+'0'),n/=10;
    reverse(s.begin(),s.end());
    return s;
}


void solve()
{
    int n;
    cin>>n;
    string s=str(n);
    int l=s.size();
    vii ans;
    for(int a=1;a<=10000;a++)
    {
        int mn=l*a-6;
        int mx=l*a-1;
        mn=max(mn,1);
        for(int b=mn;b<=mx;b++)
        {
            int i=n*a-b;
            int j=0;
            for(int i=0;i<l*a-b;i++)
            {
                j*=10;
                j+=s[i%l]-'0';
            }
            if(i==j)
            ans.push_back({a,b});
        }
    }
    cout<<ans.size()<<'\n';
    for(auto it:ans)
    cout<<it.first<<' '<<it.second<<'\n';
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