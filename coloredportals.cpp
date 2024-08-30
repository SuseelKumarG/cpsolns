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

ll dist(vvi &left,vvi &right,vii &a,int ind,int dest)
{
    int m=a[dest].first;
    int n=a[dest].second;
    ll ans=MAX;
    if(left[ind][m]!=-1)
    ans=min(ans,abs(ind-left[ind][m])+0LL+abs(left[ind][m]-dest));
    if(left[ind][n]!=-1)
    ans=min(ans,abs(ind-left[ind][n])+0LL+abs(left[ind][n]-dest));
    if(right[ind][m]!=MAX)
    ans=min(ans,abs(ind-right[ind][m])+0LL+abs(right[ind][m]-dest));
    if(right[ind][n]!=MAX)
    ans=min(ans,abs(ind-right[ind][n])+0LL+abs(right[ind][n]-dest));
    return (ans==MAX?-1:ans);
}

void solve()
{
    int n,q;
    cin>>n>>q;
    vii a(n);
    map<char,int>hsh;
    hsh['R']=0;
    hsh['G']=1;
    hsh['B']=2;
    hsh['Y']=3;
    string s;
    for(auto &it:a)
    {
        cin>>s;
        it.first=hsh[s[0]];
        it.second=hsh[s[1]];
    }
    vvi left(n,vi(4,-1));
    vvi right(n,vi(4,MAX));
    vi curr(4,-1);
    for(int i=0;i<n;i++)
    {
        int x=curr[a[i].first];
        int y=curr[a[i].second];
        left[i][a[i].first]=i;
        left[i][a[i].second]=i;
        for(int j=0;j<4;j++)
        {
            if(x!=-1)
            left[i][j]=max(left[x][j],left[i][j]);
            if(y!=-1)
            left[i][j]=max(left[i][j],left[y][j]);
        }
        curr[a[i].first]=i;
        curr[a[i].second]=i;
    }
    for(int i=0;i<4;i++)
    curr[i]=MAX;
    for(int i=n-1;i>=0;i--)
    {
        int x=curr[a[i].first];
        int y=curr[a[i].second];
        right[i][a[i].first]=i;
        right[i][a[i].second]=i;
        for(int j=0;j<4;j++)
        {
            if(x!=MAX)
            right[i][j]=min(right[x][j],right[i][j]);
            if(y!=MAX)
            right[i][j]=min(right[i][j],right[y][j]);
        }
        curr[a[i].first]=i;
        curr[a[i].second]=i;
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        if(x>y)
        swap(x,y);
        cout<<dist(left,right,a,x,y)<<'\n';
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