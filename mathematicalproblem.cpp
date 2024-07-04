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
    string s;
    cin>>s;
    if(n==2)
    {
        if(s[0]-'0')
        cout<<s<<'\n';
        else
        cout<<s[1]<<'\n';
        return;
    }
    bool zer=0;
    for(auto it:s)
    if(it=='0')
    zer=1;
    if(zer)
    {
        if(n>3)
        cout<<0<<'\n';
        else
        {
            if(s[1]-'0')
            cout<<0<<'\n';
            else
            {
                int a=s[0]-'0';
                int b=s[2]-'0';
                cout<<min(a+b,a*b)<<'\n';
            }
        }
        return;
    }
    int ans=INT_MAX;
    for(int i=0;i<n-1;i++)
    {
        vi v;
        for(int j=0;j<n;j++)
        {
            if(j==i)
            {
                int x=(s[j]-'0')*10+(s[j+1]-'0');
                v.push_back(x);
                j++;
            }
            else
            v.push_back(s[j]-'0');
        }
        int x=v[0];
        if(v[0]==1)
        x=0;
        // for(auto it:v)
        // cout<<it<<' ';
        for(int k=1;k<v.size();k++)
        {
            if(v[k]==1)
            continue;
            x+=v[k];
        }
        ans=min(ans,x);
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
        // cout<<t<<0<<'\n';
        solve();
    }
    return 0;
}