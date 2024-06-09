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
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    bool poss=1;
    int zer=0,one=0;
    for(auto it:s)
    {
        if(it=='0')
        zer++;
        else
        one++;
    }
    if(zer%k ||one%k)
    poss=0;
    if(abs(zer-one)>k)
    poss=0;
    int ans=0;
    char curr=s[0];
    int x=0;
    for(int i=n-1;i>=n-k;i--)
    {
        if(s[i]!=s[n-1])
        break;
        x++;
    }
    if(x>k)
    poss=0;
    int len=0;
    for(int i=0;i<n-k;i++)
    {
        int curr=0;
        if(s[i]==s[n-1])
        {
            while(s[i]==s[n-1]){
                i++;
                curr++;
            }
        }
        if(curr==k-x)
        {
            cout<<i<<'\n';
            ans=i;
            break;
        }
        if(curr==2*k-x)
        {
            cout<<i<<'\n';
            ans=i-k;
            break;
        }
        else if(curr!=k || curr!=2*k)
        {
            cout<<-1<<'\n';
            poss=0;
            break;
        }
    }
    // cout<<ans<<'\n';
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