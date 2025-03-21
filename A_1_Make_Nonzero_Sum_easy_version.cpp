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
    int n;
    cin>>n;
    vi a(n);
    for(auto &it:a)
    cin>>it;
    if(n&1)
    {
        cout<<-1<<'\n';
        return;
    }
    int o=0,z=0;
    int eo=0,ez=0;
    int curr=1;
    int l=0;
    vii ans;
    vii exto;
    vii extz;
    for(int i=1;i<n;i++)
    {
        if(a[i]!=a[i-1])
        {
            if(curr&1)
            {
                ans.push_back({l,i-1});
                if(a[i-1]>0)
                o++;
                else
                z++;
            }
            else
            {
                if(a[i-1]>0)
                {
                    exto.push_back({l,i-1});
                    eo+=curr;
                }
                else
                {
                    extz.push_back({l,i-1});
                    ez+=curr;
                }
            }
            curr=1;
            l=i;
        }
        else
        curr++;
    }
    ans.push_back({l,n-1});
    if(curr&1)
    {
        if(a[n-1]>0)
        o++;
        else
        z++;
    }
    set<pii>fin;
    if(((abs(o-z))&1)==0)
    {
        for(auto it:ans)
        {
            fin.insert({it.first+1,it.second+1});
        }
        int x=abs(o-z);
        if(o>z)
        {
            for(auto it:extz)
            {
                int l=it.first,r=it.second;
                while(l<=r&&x--)
                {
                    fin.insert({l+1,l+1});
                    l++;
                }
                if(l<=r)
                {
                    fin.insert({l+1,r+1});
                }
            }
            for(auto it:exto)
            {
                fin.insert({it.first+1,it.second+1});
            }
        }
        else
        {
            for(auto it:exto)
            {
                int l=it.first,r=it.second;
                while(l<=r&&x--)
                {
                    fin.insert({l+1,l+1});
                    l++;
                }
                if(l<=r)
                fin.insert({l+1,r+1});
            }
            for(auto it:extz)
            {
                fin.insert({it.first+1,it.second+1});
            }
        }
        cout<<fin.size()<<'\n';
        for(auto it:fin)
        cout<<it.first<<' '<<it.second<<'\n';

    }
    else
    cout<<-1<<'\n';
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