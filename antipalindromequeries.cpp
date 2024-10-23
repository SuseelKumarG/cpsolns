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
    vi a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    map<int,vi>cnt;
    cnt[1].push_back(0);
    cnt[2].push_back(0);
    cnt[3].push_back(0);
    int temp;
    for(int i=1;i<=3;i++)
    {
        temp=0;
        for(int j=0;j<n;j++)
        {
            temp+=(a[j]==i);
            cnt[i].push_back(temp);
        }
    }
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        int dist=r-l+1;
        if(dist%2)
        {
            cout<<"NO\n";
            continue;
        }
        l--;
        dist/=2;
        int x=cnt[1][r]-cnt[1][l-1];
        int y=cnt[2][r]-cnt[2][l-1];
        int z=cnt[3][r]-cnt[3][l-1];
        if(max({x,y,z})==dist)
        cout<<"YES\n";
        else
        cout<<"NO\n";
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