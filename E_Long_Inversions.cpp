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

bool poss(int n,int k,string s)
{
    int cnt=0;
    vi x(n+1);
    for(int i=0;i<n;i++)
    {
        if(i+k>n)
        break;
        cnt+=x[i];
        if(s[i]=='0'&&!(cnt&1))
        {
            cnt++;
            x[i+k]=-1;
        }
        if(s[i]=='1'&&(cnt&1))
        {
            cnt++;
            x[i+k]=-1;
        }
    }
    for(int i=n-k+1;i<n;i++)
    {
        cnt+=x[i];
        if(s[i]=='0'&&!(cnt&1))
        return 0;
        if(s[i]=='1'&&(cnt&1))
        return 0;
    }
    return 1;
}

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans=0;
    for(int i=n;i>0;i--)
    {
        if(poss(n,i,s))
        {
            ans=i;
            break;
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