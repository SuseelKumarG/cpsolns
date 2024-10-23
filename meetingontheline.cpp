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
const float eps=0.0000001;
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

float chk(vii &a,float mid)
{
    int n=a.size();
    float curr=0;
    for(int i=0;i<n;i++)
    {
        float temp;
        temp=abs(a[i].first-mid)+a[i].second;
        curr=max(curr,temp);
    }
    return curr;
}

void solve()
{
    int n;
    cin>>n;
    vii a(n);
    for(auto &it:a)
    cin>>it.first;
    for(auto &it:a)
    cin>>it.second;
    // sort(a.begin(),a.end());
    set<pii>ord(a.begin(),a.end());
    a.clear();
    for(auto it:ord)
    a.push_back(it);
    n=a.size();
    float l=(a.front().first),r=(a.back().first);
    // cout<<l<<' '<<r<<'\n';/
    float minm=FLT_MAX;
    float ans=r;
    float mid1,mid2;
    while(r-l>eps)
    {
        mid1=(r+2*l)/3;
        mid2=(2*r+l)/3;
        float o=chk(a,l);
        float p=chk(a,mid1);
        float q=chk(a,mid2);
        float s=chk(a,r);
        if(o<=p)
        r=mid1;
        else if(s<=q)
        l=mid2;
        else if(o<=q)
        r=mid2;
        else if(s<=p)
        l=mid1;
        else
        {
            l=mid1;
            r=mid2;
        }
    }
    cout<<r<<'\n';
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