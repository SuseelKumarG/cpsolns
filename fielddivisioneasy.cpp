//in all subarrays of array a of length k have their or same then it is true for any sub array of length > k
//END
//to coprime numbers a and b can reproduce any number x greater than a*b-a-b as x= m*a+n*b
//END
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
    int n,m,k;
    cin>>n>>m>>k;
    map<int,int>fountcol,fountrow;
    map<pii,int>fount;
    vector<bool> c(k);
    for(int i=0;i<k;i++)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        fount[{y,x}]=i;
        if(fountcol[y]<x)
        fountcol[y]=x;
        if(fountrow.find(x)==fountrow.end())
        fountrow[x]=y;
        if(fountrow[x]>y)
        fountrow[x]=y;
    }
    vii useful;
    for(auto it:fountcol)
    {
        int y=it.first;
        int x=it.second;
        if(fountrow[x]==y && fountcol[y]==x)
        useful.push_back({y,x});
    }
    ll ans=0;
    sort(useful.begin(),useful.end());
    int currrow=n,currcol=0;
    int x=useful.size();
    for(int i=0;i<x;i++)
    {
        int a=useful[i].first;
        int b=useful[i].second;
        ans+=(a-currcol+0LL)*currrow;
        while(i<x-1)
        {
            if(useful[i].first!=useful[i+1].first)
            break;
            i++;
        }
        if(currrow>n-b-1)
        {
            c[fount[{a,b}]]=1;
            currrow=n-1-b;
        }
        currcol=a;
    }
    ans+=(m-currcol)*(currrow+0LL);
    cout<<ans<<'\n';
    for(auto it:c)
    cout<<it<<' ';
    cout<<'\n'; 
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