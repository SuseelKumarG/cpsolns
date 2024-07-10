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
typedef vector<bool> vb;
typedef vector<string> vs;
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

bool poss=0;
map<char,pii> balayya;
void chk(int n,ull x,vi &a,vi &b,vi &c,char f,char s,char t)
{
    int l=0;
    ull curr=0;
    curr=0;
    balayya[f].first=l;
    for(;l<n;l++)
    {
        curr+=a[l];
        if(curr>=x)
        break;
    }
    if(curr>=x) balayya[f].second=l;
    else
    return;
    l++;
    curr=0;
    balayya[s].first=l;
    for(;l<n;l++)
    {
        curr+=b[l];
        if(curr>=x)
        break;
    }
    if(curr>=x) balayya[s].second=l;
    else
    return;
    l++;
    curr=0;
    balayya[t].first=l;
    for(;l<n;l++)
    {
        curr+=c[l];
        if(curr>=x)
        break;
    }
    if(curr>=x) balayya[t].second=l;
    else
    return;
    l++;
    poss=1;
}

void solve()
{
    poss=0;
    int n;
    cin>>n;
    vi a(n),b(n),c(n);
    ull sum=0;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
        sum+=c[i];
    }
    ull x=sum/3;
    x+=(x*3!=sum);
    chk(n,x,a,b,c,'a','b','c');
    if(poss)
    goto A;
    chk(n,x,a,c,b,'a','c','b');
    if(poss)
    goto A;
    chk(n,x,b,a,c,'b','a','c');
    if(poss)
    goto A;
    chk(n,x,b,c,a,'b','c','a');
    if(poss)
    goto A;
    chk(n,x,c,b,a,'c','b','a');
    if(poss)
    goto A;
    chk(n,x,c,a,b,'c','a','b');
    if(poss)
    goto A;
    A:
    if(poss)
    {
        cout<<balayya['a'].first+1<<' '<<balayya['a'].second+1<<' ';
        cout<<balayya['b'].first+1<<' '<<balayya['b'].second+1<<' ';
        cout<<balayya['c'].first+1<<' '<<balayya['c'].second+1<<' ';
    }
    else
    cout<<-1;
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