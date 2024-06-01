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

bool poss=0;

void check(int a,int b,vi &arr)
{
    if(poss)
    return;
    if(a+1==b-1)
    {
        if(arr[a]==arr[b])
        {
            arr[a+1]=arr[a]<<1;
            poss=1;
        }
        return;
    }
    if(a+1==b)
    {
        if((arr[a]*2)==arr[b] || (arr[a]/2)==arr[b])
        poss=1;
        return;
    }
    if(arr[a+1]!=-1)
    {
        poss=1;
        return;
    }
    if(arr[b-1]!=-1)
    {
        poss=1;
        return;
    }
    arr[a+1]=2*arr[a];
    arr[b-1]=2*arr[b];
    check(a+1,b-1,arr);
    if(arr[a]!=1)
    arr[a+1]=arr[a]/2;
    arr[b-1]=2*arr[b];
    check(a+1,b-1,arr);
    if(arr[b]!=1)
    arr[b-1]=arr[b]/2;
    arr[a+1]=arr[a]*2;
    check(a+1,b-1,arr);
    if(arr[a]!=1 && arr[b]!=1)
    {
        arr[b-1]=arr[b]/2;
        arr[a+1]=arr[a]/2;
        check(a+1,b-1,arr);
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
            lind=i;
            break;
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]!=-1)
        {
            rind=i;
            break;
        }
    }
    queue<int>q;
    for(int i=0;i<n;i++)
    {
        if(!i)
        {
            if(a[i]!=-1 &&a[i+1]==-1)
            q.push(i);
        }
        else if(i==n-1)
        {
            if(a[i]!=-1 &&a[i-1]==-1)
            q.push(i);
        }
        else
        {
            if(a[i]!=-1&&(a[i-1]==-1||a[i+1]==-1))
            q.push(i);
        }
    }
    if(lind==-1)
    {
        for(int i=0;i<n;i++)
        cout<<2-(i%2)<<' ';
        cout<<'\n';
        return;
    }
    for(int i=lind-1;i>=0;i--)
    {
        if(a[i+1]!=a[lind])
        a[i]=a[lind];
        else
        a[i]=a[lind]<<1;
    }
    for(int i=rind+1;i<n;i++)
    {
        if(a[i-1]!=a[rind])
        a[i]=a[rind];
        else
        a[i]=a[rind]<<1;
    }
    bool done=1;
    int x=q.front();
    q.pop();
    int y=q.front();
    while(q.size()>1)
    {
        poss=0;
        check(x,y,a);
        if(poss)
        {
            x=y;
            q.pop();
            y=q.front();
        }
        else
        {
            done=0;
            break;
        }
    }
    if(done)
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