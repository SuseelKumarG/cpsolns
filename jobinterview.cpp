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
    int x=n+m+1;
    vii pt(x);
    for(int i=0;i<x;i++) cin>>pt[i].first;
    for(int i=0;i<x;i++) cin>>pt[i].second;
    int walter_white=-1;
    vb p(x);
    ll sum=0;
    for(int i=0;i<x-1;i++)
    {
        if(pt[i].first>pt[i].second)
        {
            if(n)
            {
                n--;
                p[i]=1;
                sum+=pt[i].first;
            }
            else
            {
                if(walter_white==-1) walter_white=i;
                sum+=pt[i].second;
            }
        }
        else
        {
            if(m)
            {
                m--;
                sum+=pt[i].second;
            }
            else
            {
                p[i]=1;
                sum+=pt[i].first;
                if(walter_white==-1) walter_white=i;
            }
        }
    }
    // cout<<sum<<'\n';
    for(auto it:p)
    cout<<it<<' ';
    cout<<'\n';
    for(int i=0;i<x;i++)
    {
        if(i<walter_white&&p[walter_white]!=p[i])
        {
            if(p[i])
            cout<<sum+pt[walter_white].first-pt[walter_white].second-pt[i].first+pt[x-1].second;
            else
            cout<<sum+pt[walter_white].second-pt[walter_white].first-pt[i].second+pt[x-1].first;
            // cout<<
        }
        else
        {
            if(p[i])
            cout<<sum-pt[i].first+pt[x-1].first;
            else
            cout<<sum-pt[i].second+pt[x-1].second;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    cin>>t;
    while(t--)
    {
        // cout<<t<<"YO\n";
        solve();
    }
    return 0;
}