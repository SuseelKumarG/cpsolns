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
    for(int i=0;i<=n-k;i++)
    {
        if(s[i]=='0')
        {
            int ind=-1;
            for(int j=0;j<k;j++)
            {
                if(i+j<n)
                {
                    s[i+j]=(!(s[i+j]-'0')+'0');
                    if(!(s[i+j]-'0')&&ind==-1)
                    ind=i+j;
                }
                else
                {
                    // cout<<i<<' '<<j<<' '<<k<<'\n';
                    return 0;
                }
            }
            i=ind-1;
        }
    }
    cout<<s<<'\n';
    for(int i=n-k;i<n;i++)
    {
        if(s[i]!='1')
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
    set<char>ch;
    for(auto it:s)
    ch.insert(it);
    int ans=1;
    int k=0;
    string x=s;
    sort(all(x));
    for(auto it:x)
    if(it=='0')
    k++;
    if(ch.size()==1)
    {ans=n;
    goto A;}
    for(int i=n;i>0;i--)
    if(poss(n,i,s))
    {ans=i;
    break;}
    A:
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
        // cout<<t<<0<<'\n';
        // cout<<t<<'\n';
        solve();
    }
    return 0;
}