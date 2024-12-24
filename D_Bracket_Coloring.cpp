#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
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
int maxLength(string s, int n)
{
    int op=0,end=0;
    for(auto it:s)
    {
        if(it=='(')
        {
            op++;
        }
        else
        {
            if(op)
            {
                op--;
            }
            else
            {
                end++;
            }
        }
    }
    return n-(op+end);
}
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<char,int>cnt;
    for(auto it:s)
    {
        cnt[it]++;
    }
    if(n&1||cnt['(']!=cnt[')'])
    {
        cout<<-1<<'\n';
        return;
    }
    int x=maxLength(s,n)/2;
    vi a(n);
    stack<char>ok;
    for(int i=0;i<n;i++)
    {
        if(x&&s[i]=='(')
        {
            x--;
            ok.push('(');
            a[i]=1;
        }
        if(s[i]==')'&&!ok.empty())
        {
            ok.pop();
            a[i]=1;
        }
    }
    string temp=s;
    reverse(temp.begin(),temp.end());
    if(maxLength(s,n)==n||maxLength(temp,n)==n)
    {
        cout<<1<<'\n';
        for(int i=0;i<n;i++)
        cout<<1<<' ';
        cout<<'\n';
    }
    else if(maxLength(s,n)==0)
    {
        cout<<1<<'\n';
        for(int i=0;i<n;i++)
        cout<<1<<' ';
        cout<<'\n';
    }
    else
    {
        cout<<2<<'\n';
        for(int i =0;i<n;i++)
        {
            if(a[i])
            cout<<1<<' ';
            else
            cout<<2<<' ';
        }
        cout<<'\n';
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
        solve();
    }
    return 0;
}