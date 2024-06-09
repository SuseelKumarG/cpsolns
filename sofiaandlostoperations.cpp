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
    bool poss=1;
    int n;
    cin>>n;
    vi a(n),b(n);
    set<int>val;
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
        val.insert(b[i]);
    }
    int m;
    cin>>m;
    map<int,vi>chk;
    vi c(m);
    for(int i=0;i<m;i++)
    {
        cin>>c[i];
        chk[c[i]].push_back(i);
    }
    for(int i=0;i<n && poss;i++)
    {
        if(a[i]!=b[i])
        {
            if(chk[b[i]].empty())
            poss=0;
            else
            {
                c[chk[b[i]].back()]=0;
                chk[b[i]].pop_back();
                a[i]=b[i];
            }
        }
    }
    for(auto it:chk)
    {
        if(val.find(it.first)!=val.end())
        {
            for(auto sit:it.second)
            c[sit]=0;
        }
    }
    if(c[m-1])
    poss=0;
    for(int i=0;i<n;i++)
    if(a[i]!=b[i])
    poss=0;
    cout<<(poss?"YES":"NO")<<'\n';
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