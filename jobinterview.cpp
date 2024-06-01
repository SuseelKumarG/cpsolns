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
    int n,m;
    cin>>n>>m;
    vi cp(n+m+1);
    vi ct(n+m+1);
    for(int i=0;i<n+m+1;i++)
    cin>>cp[i];
    for(int i=0;i<n+m+1;i++)
    cin>>ct[i];
    vector<bool>p(n+m+1);
    map<int,set<pair<int,int>>>pro;
    if(n)
    {for(int i=0;i<n+m+1;i++)
    {
        if(cp[i]>ct[i])
        {
            if(pro.size()==n)
            {
                auto it=pro.begin();
                if(it->first<cp[i])
                {
                    p[i]=1;
                    p[(--(it->second.end()))->second]=0;
                    it->second.erase((--(it->second.end())));
                    if(it->second.empty())
                    pro.erase(it);
                    pro[cp[i]].insert({ct[i],i});
                }
                else if(it->first==cp[i])
                {
                    if(pro[cp[i]].end()->first>ct[i])
                    {
                        p[(--(it->second.end()))->second]=0;
                        it->second.erase((--(it->second.end())));
                        pro[cp[i]].insert({ct[i],i});
                        p[i]=1;
                    }
                }
            }
            else
            {
                pro[cp[i]].insert({ct[i],i});
                p[i]=1;
            }
        }
    }}
    int sum=0;
    for(int i=0;i<n+m+1;i++)
    {
        if(p[i])
        sum+=cp[i];
        else
        sum+=ct[i];
    }
    // for(int i=0;i<n+m+1;i++)
    // {
    //     if(p[i])
    //     cout<<sum-cp[i]<<' ';
    //     else
    //     cout<<sum-ct[i]<<' ';
    // }
    for(auto it:p)
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