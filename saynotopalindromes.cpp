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
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    vector<string>ord(6);
    ord[0]="abc";
    ord[1]="acb";
    ord[2]="bac";
    ord[3]="bca";
    ord[4]="cab";
    ord[5]="cba";
    vector<string>chk(6);
    for(int i=0;i<6;i++)
    {
        while(chk[i].length()<n)
        chk[i]+=ord[i];
        while(chk[i].length()>n)
        chk[i].pop_back();
    }
    vvl pre(6,vl(n+10));
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<n;j++)
        pre[i][j+1]=pre[i][j]+(chk[i][j]!=s[j]);
    }
    int l,r;
    ll ans=INT_MAX;
    while(m--)
    {
        cin>>l>>r;
        ans=INT_MAX;
        for(int i=0;i<6;i++)
        ans=min(ans,pre[i][r]-pre[i][l-1]);
        cout<<ans<<'\n';
    }
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