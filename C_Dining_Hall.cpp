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

ll binexp(ll a,ll b)
{
    ll ans=1;
    while (b)
    {
        if(b&1)
        ans=(ans*a)%MAX;
        b>>=1;
        a=(a*a)%MAX;
    }
    return ans;
}

void solve()
{
    int n;
    cin>>n;
    set<pair<int,pii>>temp;
    int curr=0;
    int t=0;;
    while(temp.size()<n)
    {
        for(int i=0;i<=curr;i++)
        {
            if(t==n)
            break;
            t++;
            temp.insert({curr*3,{i*3,(curr-i)*3}});
        }
        curr++;
    }   
    set<pair<int,pii>>ord;
    for(auto it:temp)
    {
        ord.insert({it.first,it.second});
        ord.insert({it.first+1,{it.second.first+1,it.second.second}});
        ord.insert({it.first+1,{it.second.first,it.second.second+1}});
        ord.insert({it.first+4,{it.second.first+1,it.second.second+1}});
    }
    while(n--)
    {
        int x;
        cin>>x;
        if(x)
        {
            cout<<(ord.begin()->second).first+1<<' '<<(ord.begin()->second).second+1<<'\n';
            int y=((ord.begin()->second).first)%3+((ord.begin()->second).second)%3;
            temp.erase({ord.begin()->first+y,ord.begin()->second});
            ord.erase(ord.begin());
        }
        else
        {
            cout<<(temp.begin()->second).first+1<<' '<<(temp.begin()->second).second+1<<'\n';
            ord.erase({temp.begin()->first,temp.begin()->second});
            temp.erase(temp.begin());
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