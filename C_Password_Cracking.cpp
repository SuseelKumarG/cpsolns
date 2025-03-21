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

int outp(string s)
{
    cout<<"? "+s<<endl;
    int x;
    cin>>x;
    return x;
}

void solve()
{
    int n;
    cin>>n;
    string s;
    int cnt=0;
    int rev=0;
    while(s.length()!=n)
    {   
        if(!rev)
        {
            if(!cnt)
            {
                if(outp(s+"0"))
                {
                    s+="0";
                    cnt=0;
                }
                else
                cnt++;
            }
            else
            {
                if(outp(s+"1"))
                {
                    s+="1";
                    cnt=0;
                }
                else
                {
                    cnt=0;
                    rev=1;
                }
            }
        }
        else
        {
            if(!cnt)
            {
                if(outp("0"+s))
                {
                    s="0"+s;
                    cnt=0;
                }
                else
                cnt++;
            }
            else
            {
                s="1"+s;
                cnt=0;
            }
        }
    }
    cout<<"! "+s<<endl;
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