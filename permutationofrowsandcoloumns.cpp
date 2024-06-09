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

void solve()
{
    bool poss=1;
    int n,m;
    cin>>n>>m;
    vvi a(n),b(n);
    vi temp(m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cin>>temp[j];
        a[i]=temp;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cin>>temp[j];
        b[i]=temp;
    }
    set<set<int>>ar;
    set<set<int>>ac;
    set<set<int>>br;
    set<set<int>>bc;
    set<int>bot;
    set<int>bot1;
    for(int i=0;i<n;i++)
    {
        bot.clear();
        bot1.clear();
        for(int j=0;j<m;j++)
        {
            bot.insert(a[i][j]);
            bot1.insert(b[i][j]);
        }
        ar.insert(bot);
        br.insert(bot1);
    }
    for(int i=0;i<m;i++)
    {
        bot.clear();
        bot1.clear();
        for(int j=0;j<n;j++)
        {
            bot.insert(a[j][i]);
            bot1.insert(b[j][i]);
        }
        ac.insert(bot);
        bc.insert(bot1);
    }
    if(ar!=br || ac!=bc)
    poss=0;
    cout<<(poss?"YES":"NO")<<'\n';
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