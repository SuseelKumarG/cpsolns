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
typedef vector<pll> vll; 
typedef vector<bool> vb;
#define all(x) x.begin(),x.end()
#define MAX 1000000007
#define N 20015

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
    int n;
    cin>>n;
    int m;
    cin>>m;
    string s;
    cin>>s;
    vi a(m);
    for(int i=0;i<m;i++)
    cin>>a[i];
    string c;
    cin>>c;
    sort(all(a));
    sort(all(c));
    queue<char>ch;
    for(int i=0;i<m;i++)
    ch.push(c[i]);
    vb vis(m,0);
    vb chk(m,0);
    int x=0;
    for(int i=m-1;i>=0;i--)
    {
        if(a[i]!=x)
        {
            x=a[i];
            vis[i]=1;
        }
    }
    for(int i=0;i<m;i++)
    {
        if(vis[i])
        {
            c[i]=ch.front();
            ch.pop();
        }
    }
    for(int i=0;i<m;i++)
    {
        if(!vis[i])
        {
            c[i]=ch.front();
            ch.pop();
            vis[i]=1;
        }
    }
    for(int i=0;i<m;i++)
    s[a[i]-1]=c[i];
    cout<<s<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    cin>>t;
    while(t--)
    {
        // cout<<t<<0<<'\n';
        solve();
    }
    return 0;
}