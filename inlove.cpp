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
typedef vector<pll> vll; 
typedef vector<bool> vb;
#define MAX 1000000007
#define N 20015

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
    int t;
    cin>>t;
    multiset<int> lb,rb;
    char ch;
    int l,r;
    while(t--)
    {
        cin>>ch>>l>>r;
        if(ch=='+')
        {
            lb.insert(l);
            rb.insert(r);
        }
        else
        {
            lb.erase(lb.find(l));
            rb.erase(rb.find(r));
        }
        bool poss=0;
        if(!rb.empty()&&!lb.empty())
        if((*rb.begin())<(*(--(lb.end()))))
        poss=1;
        cout<<(poss?"YES":"NO")<<'\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    // cin>>t;
    while(t--)
    {
        // cout<<t<<0<<'\n';
        solve();
    }
    return 0;
}