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
    int n;
    cin>>n;
    vi a(n);
    for(auto &it:a)
    cin>>it;
    stack<int>pos;
    stack<int>neg;
    for(auto it:a)
    {
        if(it>0)
        pos.push(it);
        if(it<0)
        neg.push(it);
    }
    ll sum=0;
    if(pos.empty())
    {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    for(int i=0;i<n;i++)
    {
        if(sum>0)
        {
            sum+=neg.top();
            cout<<neg.top()<<' ';
            neg.pop();
        }
        else if(sum)
        {
            sum+=pos.top();
            cout<<pos.top()<<' ';
            pos.pop();
        }
        else
        {
            if(neg.empty())
            cout<<0<<' ';
            else
            {
                sum+=neg.top();
                cout<<neg.top()<<' ';
                neg.pop();
            }
        }
    }
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