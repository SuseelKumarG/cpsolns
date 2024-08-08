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
    int n,q;
    cin>>n>>q;
    string a,b;
    cin>>a>>b;
    vvi ca(n+1,vi(26)),cb;
    cb=ca;
    for(int i=0;i<n;i++)
    {
        ca[i+1]=ca[i];
        cb[i+1]=cb[i];
        ca[i+1][a[i]-'a']++;
        cb[i+1][b[i]-'a']++;
    }
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        l--;
        int ans=0;
        vi aa(26),bb;
        bb=aa;
        for(int i=0;i<26;i++)
        {
            aa[i]=ca[r][i]-ca[l][i];
            bb[i]=cb[r][i]-cb[l][i];
        }
        for(int i=0;i<26;i++)
        ans+=abs(aa[i]-bb[i]);
        cout<<ans/2<<'\n';
    }
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