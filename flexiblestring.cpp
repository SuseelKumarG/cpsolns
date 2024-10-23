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
    int n,k;
    cin>>n>>k;
    string a,b;
    cin>>a>>b;
    set<char> unq;
    for(auto it:a)
    unq.insert(it);
    int diff=unq.size();
    int minm=min(diff,k);
    vector<char> choice(unq.begin(),unq.end());
    ll ans=0;
    for(int i=0;i<(1<<diff);i++)
    {
        if(__builtin_popcount(i)!=minm)
        continue;
        int ind=0;
        int x=i;
        string s=a;
        ll curr=0;
        while(x)
        {
            if(x&1)
            {
                char ch=choice[ind];
                for(int i=0;i<n;i++)
                {
                    if(s[i]==ch)
                    {
                        if(s[i]!=b[i])
                        s[i]=b[i];
                    }
                }
            }
            ind++;
            x>>=1;
        }
        ll temp=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]==b[i])
            temp++;
            else
            {
                curr+=(temp*(temp+1))/2;
                temp=0;
            }
        }
        curr+=(temp*(temp+1))/2;
        ans=max(ans,curr);
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