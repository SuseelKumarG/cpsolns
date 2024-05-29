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
    vi a(n),b;
    for(int i=0;i<n;i++)
    cin>>a[i];
    bool poss=1;
    int ind=-1;
    for(int i=0;i<n-1;i++)
    {
        if(a[i]>a[i+1])
        {
            ind=i;
            break;
        }
    }if(ind!=-1)
    {
        for(int i=ind+1;i<n;i++)
        b.push_back(a[i]);
        for(int i=0;i<=ind;i++)
        b.push_back(a[i]);
        for(int i=0;i<n-1;i++)
        if(b[i]>b[i+1])
        poss=0;
    }
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