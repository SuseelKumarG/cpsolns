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

ll sqr(ll x)
{
    ll lo=0,hi=x;
    ll mid;
    while(hi-lo>1)
    {
        mid=(hi-lo)/2+lo;
        if(mid*mid<x)
        lo=mid;
        else
        hi=mid;
    }
    if(hi*hi<=x)
    return hi;
    return lo;
    // cout<<lo<<' '<<hi<<'\n'; 
}

void solve()
{
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    map<string,vi>bitgrp;
    for(int i=0;i<n;i++)
    {
        string s;
        int x=a[i];
        while(x)
        {
            if(x&1)
            s.push_back('1');
            else
            s.push_back('0');
            x>>=1;
        }
        reverse(s.begin(),s.end());
        if(!s.empty())
        s.pop_back();
        if(!s.empty())
        s.pop_back();
        bitgrp[s].push_back(i);
    }
    for(auto it:bitgrp)
    {
        vi temp=it.second;
        vi temp1;
        for(auto it:temp)
        temp1.push_back(a[it]);
        sort(temp1.begin(),temp1.end());
        for(int i=0;i<temp.size();i++)
        a[temp[i]]=temp1[i];
    }
    for(auto it:a)
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