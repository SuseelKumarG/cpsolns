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

bool casee(int x,vi &a,int n)
{
    if(x<0)
    return 0;
    vi ax(n-1);
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(i!=x)
        {ax[c]=a[i];
        c++;}
    }
    vi b(n-2);
    for(int i=0;i<n-2;i++)
    {
        b[i]=gcd(ax[i],ax[i+1]);
    }
    for(int i=0;i<n-3;i++)
    {
        if(b[i]>b[i+1])
        return 0;
    }
    
    return 1;
}


void solve()
{
    bool poss=1;
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    // if(gcd(a[0],a[1])==1||gcd(a[2],a[1])==1||gcd(a[0],a[2])==1)
    // {
    //     cout<<"YES\n";
    //     return;
    // }
    vi b(n-1);
    for(int i=0;i<n-1;i++)
    {
        b[i]=gcd(a[i],a[i+1]);
    }
    int ind=-1;
    for(int i=0;i<n-2;i++)
    {
        if(b[i]>b[i+1])
        {
            ind=i;
            break;
        }
    }
    if(ind<0)
    {
        cout<<"YES\n";
        return;
    }
    poss=(casee(ind,a,n)||casee(ind+2,a,n)||casee(ind+1,a,n));
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