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

map<string,int>cnt;

void chk(int i,int j,vector<string> &a,int n,string &s)
{
    if(i>1)
    return;
    if(j>=n)
    return;
    s.push_back(a[i][j]);
    if(i==1&&j==n-1)
    cnt[s]++;
    chk(i,j+1,a,n,s);
    if(!i)
    chk(i+1,j,a,n,s);
    s.pop_back();
}

void solve()
{
    int n;
    cin>>n;
    vector<string>a(2);
    cin>>a[0]>>a[1];
    ll ans=1;
    int i=0;
    string s;
    int j;
    for(j=0;j<n-1;)
    {
        s.push_back(a[i][j]);
        if(!i)
        {
            if(a[i][j+1]==a[i+1][j])
            {
                // cout<<i<<' '<<j<<" 1"<<'\n';
                ans++;
                j++;
            }
            else if(a[i][j+1]<a[i+1][j])
            {
                ans=1;
                // cout<<i<<' '<<j<<" 2"<<'\n';
                j++;
            }
            else
            {
                i++;
            }
        }
        else
        {
            j++;
        }
    }
    s.push_back(a[i][j]);
    if(!i)
    s.push_back(a[i+1][j]);
    cout<<s<<'\n';
    cout<<(ans? ans:1)<<'\n';
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