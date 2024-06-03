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

bool check(int x,int y,vi &a)
{
    int steps=y-x-1;
    int m=a[x],n=a[y];
    vi bm(32),bn(32);
    for(int i=0;i<32;i++)
    {
        if(m&(1<<i))
        bm[i]=1;
        if(n&(1<<i))
        bn[i]=1;
    }
    while(bm.back()==0)
    bm.pop_back();
    while(bn.back()==0)
    bn.pop_back();
    reverse(bm.begin(),bm.end());
    reverse(bn.begin(),bn.end());
    int mins=min(bm.size(),bn.size());
    int cnt=0;
    for(int i=0;i<mins;i++)
    {
        if(bm[i]==bn[i])
        cnt++;
        else
        break;
    }
    int diff=bm.size()-cnt+bn.size()-cnt;
    if(diff-1==steps)
        return 1;
    if(diff>steps)
        return 0;
    if((steps-diff)&1)
    return 1;
    else
    return 0;
}

void fill(int x,int y,vi &a)
{
    int steps=y-x-1;
    int m=a[x],n=a[y];
    vi bm(32),bn(32);
    for(int i=0;i<32;i++)
    {
        if(m&(1<<i))
        bm[i]=1;
        if(n&(1<<i))
        bn[i]=1;
    }
    while(bm.back()==0)
    bm.pop_back();
    while(bn.back()==0)
    bn.pop_back();
    reverse(bm.begin(),bm.end());
    reverse(bn.begin(),bn.end());
    int mins=min(bm.size(),bn.size());
    int cnt=0;
    for(int i=0;i<mins;i++)
    {
        if(bm[i]==bn[i])
        cnt++;
        else
        break;
    }
    int diff=bm.size()-cnt+bn.size()-cnt;
    int i=x+1;
    int temp=bm.size()-cnt;
    while(temp>0)
    {
        bm.pop_back();
        reverse(bm.begin(),bm.end());
        int ans=0;
        for(int i=0;i<bm.size();i++)
        {
            if(bm[i])
            ans+=(1<<i);
        }
        a[i]=ans;
        i++;
        temp--;
        reverse(bm.begin(),bm.end());
    }
    temp=bn.size()-cnt;
    reverse(bn.begin(),bn.end());
    for(int i=0;i<cnt;i++)
    bn.pop_back();
    while(temp>0)
    {
        bm.push_back(bn[bn.size()-1]);
        bn.pop_back();
        reverse(bm.begin(),bm.end());
        int ans=0;
        for(int i=0;i<bm.size();i++)
        {
            if(bm[i])
            ans+=(1<<i);
        }
        a[i]=ans;
        i++;
        temp--;
        reverse(bm.begin(),bm.end());
    }
    temp=steps-diff;
    while(temp>0)
    {
        if(a[i-1]==a[y])
        a[i]=a[y]<<1;
        else
        a[i]=a[y];
        i++;
        temp--;
    }
}

void solve()
{
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    int lind=-1,rind=-1;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=-1)
        {
            if(lind==-1)
            lind=i;
            rind=i;
        }
    }
    if(lind==-1)
    {
        for(int i=0;i<n;i++)
        cout<<2-(i&1)<<' ';
        cout<<'\n';
        return;
    }
    for(int i=lind-1;i>=0;i--)
    {
        if(a[i+1]==a[lind])
        a[i]=a[lind]<<1;
        else
        a[i]=a[lind];
    }
    for(int i=rind+1;i<n;i++)
    {
        if(a[i-1]==a[rind])
        a[i]=a[rind]<<1;
        else
        a[i]=a[rind];
    }
    bool poss=1;
    int x=-1,y=-1;
    vi bx(32),by(32);
    bool start=0;
    for(int i=lind;i<=rind&&poss;i++)
    {
        if(a[i]!=-1)
        {
            if(start)
            {
                y=i;
                if(check(x,y,a))
                {
                    fill(x,y,a);
                }
                else
                {
                    // cout<<x<<' '<<y<<'\n';
                    poss=0;
                }
                start=0;
            }
            x=i;
        }
        else
        start=1;
    }
    if(a[0]!=a[1]/2 && a[1]!=a[0]/2)
    poss=0;
    if(a[n-1]!=a[n-2]/2 && a[n-2]!=a[n-1]/2)
    poss=0;
    for(int i=1;i<n-1;i++)
    {
        if((a[i]!=a[i-1]/2 && a[i-1]!=a[i]/2)  || (a[i]!=a[i+1]/2 && a[i+1]!=a[i]/2))
        poss=0;
    }
    if(poss)
    {
        for(auto it:a)
        cout<<it<<' ';
        cout<<'\n';
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