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

void solve()
{
    string s;
    cin>>s;
    int n=s.length();
    int q;
    cin>>q;
    ll temp=1;
    vi ok;
    while(temp<1e18&&temp>0)
    {
        ok.push_back(temp);
        temp*=2;
    }
    while(q--)
    {
        ll x;
        cin>>x;
        x--;
        ll y=x/n;
        x=x-y*n;
        if(!y)
        {
            cout<<s[x]<<' ';
            continue;
        }
        int pos=upper_bound(ok.begin(),ok.end(),y)-ok.begin();
        pos--;
        pos=y-ok[pos];
        cout<<y<<' '<<pos<<' ';
        if(!(pos&1))
        {
            if(s[x]>'Z')
                cout<<char(s[x]-('a'-'A'))<<' ';
                else
                cout<<char(s[x]+('a'-'A'))<<' ';
        }
        else
        cout<<s[x]<<' ';
        cout<<'\n';
    }
    cout<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    while(t--)
    {
        solve();
    }
    return 0;
}