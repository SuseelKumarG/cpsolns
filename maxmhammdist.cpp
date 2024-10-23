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

void solve()
{
    int m,n;
    cin>>n>>m;
    vector<string>s(m);
    for(auto &it:s)
    cin>>it;
    vvi one(m,vi(n)),zer(m,vi(n));
    int temp=0,cnt=0;
    for(int i=0;i<n;i++)
    {
        temp=0,cnt=0;
        for(int j=0;j<m;j++)
        {
            if(s[j][i]=='0')
            temp++;
            if(s[j][i]=='1')
            cnt++;
        }
        for(int j=0;j<m;j++)
        {
            if(s[j][i]!='?')
            continue;
            if(temp>cnt)
            {
                s[j][i]='1';
                cnt++;
            }
            else
            {
                s[j][i]='0';
                temp++;
            }
        }
    }
    for(int i=m-2;i>=0;i--)
    {
        for(int j=0;j<n;j++)
        {
            zer[i][j]=zer[i+1][j]+(s[i+1][j]=='0');
            one[i][j]=one[i+1][j]+(s[i+1][j]=='1');
        }
    }
    ll ans=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(s[i][j]=='0')
            ans+=one[i][j];
            else
            ans+=zer[i][j];
        }
    }
    cout<<ans<<'\n';
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