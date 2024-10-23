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

void balayya(set<string>&chk,int diff,int n,vi &cnt,string a)
{
    int freq=n/diff;
    set<pair<int,int>>ord;
    for(int i=0;i<26;i++)
    {
        if(ord.size()<diff)
        ord.insert({min(freq,cnt[i]),i});
        else
        {
            if(ord.begin()->first<min(freq,cnt[i]))
            {
                ord.erase(ord.begin());
                ord.insert({min(freq,cnt[i]),i});
            }
        }
    }
    int ans=0;
    map<char,int>rem;
    set<char>imp;
    for(auto it:ord)
    {
        char ch='a'+it.second;
        imp.insert(ch);
        int curr=0;
        int goal=it.first;
        for(int i=0;i<n;i++)
        {
            if(a[i]==ch)
            {
                if(curr<goal)
                curr++;
                else
                a[i]='$';
            }
        }
        if(curr<freq)
        rem[ch]=freq-curr;
    }
    for(int i=0;i<n;i++)
    {
        if(imp.find(a[i])==imp.end())
        {
            a[i]='$';
        }
    }
    for(auto it:rem)
    {
        char ch=it.first;
        int goal=it.second;
        for(int i=0;i<n;i++)
        {
            if(a[i]=='$'&&goal)
            {
                goal--;
                a[i]=ch;
            }
        }
    }
    chk.insert(a);
}

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    vi cnt(26);
    for(auto it:s)
    cnt[it-'a']++;
    set<string> chk;
    for(int i=1;i<=min(n,26);i++)
    {
        if(n%i)
        continue;
        balayya(chk,i,n,cnt,s);
    }
    ll ans=100000000;
    string x;
    for(auto it:chk)
    {
        string a=it;
        ll curr=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]!=s[i])
            curr++;
        }
        if(ans>curr)
        {
            ans=curr;
            x=a;
        }
    }
    cout<<ans<<'\n';
    cout<<x<<'\n';
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