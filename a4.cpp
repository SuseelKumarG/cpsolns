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

vector<vii> adjvec()
{
    int n,m;
    cin>>n>>m;
    vector<vii> graph(n);
    while(m--)
    {
        int v1,v2,w=1;
        cin>>v1>>v2;
        v1--;
        v2--;
        cin>>w;
        graph[v1].push_back({v2,w});
        graph[v2].push_back({v1,w});
    }
    return graph;
}

long long gcd(long long a, long long b){
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

int outp(int i,int j)
{
    printf("? %d %d\n",i,j);
    fflush(stdout);
    int x;
    cin>>x;
    return x;
}
void out(int i,int j)
{
    printf("! %d %d\n",i,j);
    fflush(stdout);
}


void solve()
{
    int n;
    cin>>n;
    vi a(n);
    bool came=0;
    int now=2;
    int past=-1;
    int prev=-1;
    int ones=0;
    while(came==0&&now<=n)
    {
        int x=outp(now-1,now);
        if(x==0)
        {
            now++;
            continue;
        }
        came=1;
        past=now-1;
        prev=1;
        a[now-2]=0;
        a[now-1]=1;
        ones=1;
        if(outp(1,now)==1)
        {
            for(int i=0;i<now-2;i++)
            a[i]=1;
        }
        else
        {
            for(int i=0;i<now-2;i++)
            a[i]=0;
        }
        now+=2;
    }
    if(came)
    {
        while(now<=n)
        {
            int x=outp(now-1,now);
            if(x==1)
            {
                a[now-1]=1;
                past=now-1;
            }
            else
            {
                if(a[now-2]==0)
                {
                    a[now-1]=0;
                    ones=0;
                    past=now;
                }
                else
                {
                    if(outp(past,now)==ones)
                    {
                        a[now-1]=0;
                        ones=0;
                        past=now;
                    }
                    else
                    {
                        a[now-1]=1;
                        ones++;
                    }
                }
            }
            now++;
        }
    }
    if(came)
    {
        cout<<"! ";
        for(auto it:a)
        cout<<it;
        cout<<endl;
    }
    else
    cout<<"! IMPOSSIBLE"<<endl;
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