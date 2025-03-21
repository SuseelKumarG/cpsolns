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

int que(int i,int j,int k)
{
    cout<<"? "<<i<<' '<<j<<' '<<k<<endl;
    int x;
    cin>>x;
    return x;
}

void solve()
{
    int n;
    cin>>n;
    vi a(n);
    int t1=que(1,2,3);
    int t2=que(2,3,4);
    int of=t1-t2;
    int t3=que(1,3,4);
    int tf=t1-t3;
    int t4=que(1,2,4);
    int twf=t1-t4;
    a[3]=-1*(((of+tf+twf)-t1))/3;
    a[0]=a[3]+of;
    a[1]=a[3]+tf;
    a[2]=a[3]+twf;
    for(int i=2;i<n-2;i++)
    {
        int temp=que(i+1,i+2,i+3);
        a[i+2]=temp-a[i]-a[i+1];
    }
    cout<<"! ";
    for(auto it:a)
    cout<<it<<" ";
    cout<<endl;
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