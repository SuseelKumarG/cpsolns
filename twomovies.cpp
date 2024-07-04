//in all subarrays of array a of length k have their or same then it is true for any sub array of length > k
//END
//to coprime numbers a and b can reproduce any number x greater than a*b-a-b as x= m*a+n*b
//END
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
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
typedef vector<vb> vvb;
#define all(x) x.begin(),x.end()
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
    int n;
    cin>>n;
    vi a(n),b(n);
    for(int i=0;i<n;i++)
    cin>>a[i];   
    for(int i=0;i<n;i++)
    cin>>b[i];
    int po=0,ne=0;
    int ar=0,br=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>b[i])
        ar+=a[i];
        if(b[i]>a[i])
        br+=b[i];
        if(a[i]==b[i]&&a[i]==1)
        po++;
        if(a[i]==b[i]&&a[i]==-1)
        ne++;
    }
    while(po--)
    if(ar<br) ar++;
    else br++;
    while(ne--)
    if(ar>br) ar--;
    else br--;
    cout<<min(ar,br)<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    cin>>t;
    while(t--)
    {
        // cout<<t<<"YO"<<'\n';
        solve();
    }
    return 0;
}