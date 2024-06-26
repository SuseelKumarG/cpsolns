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



void solve()
{
    int n;
    cin>>n;
    vi bit(32);
    for(int i=0;i<32;i++)
    {
        if(n&(1<<i))
        bit[i]=1;
    }
    bool start=0;
    if(bit[0]&&bit[1])
    {
        bit[0]=-1;
        start=1;
    }
    for(int i=1;i<31;i++)
    {
        if(start)
        {
            if(bit[i])
            bit[i]=0;
            else
            {
                bit[i]=1;
                start=0;
            }
        }
        else
        {
            if(bit[i]&&bit[i-1])
            {
                bit[i-1]=-1;
                bit[i]=0;
                start=1;
            }
        }
    }
    // start=1;
    if(start)
    bit[31]=1;
    cout<<bit.size()<<'\n';
    for(auto it:bit)
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