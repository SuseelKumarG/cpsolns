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
#define MAX 1000000007
#define eps 0.000000001
const int N=1000005;
    int n;
bool exist(vvi &arr,int &c,int &r)
{
    if(r>=n)
    return 1;
    if(c==1)
    {
        if(arr[0][r])
            arr[c--][r]=0;
    }
    else if(c==0)
    {
        if(arr[1][r])
            arr[c++][r]=0;
    }
    else if(arr[c][r+1])
        arr[c][r++]=0;
    else return 0;
    return 1; 
}

void solve()
{

    cin>>n;
    vector<string> wall(2);
    cin>>wall[0]>>wall[1];
    int black=0;
    bool poss=1;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(wall[i][j]=='B')
            {
                black++;
            }
            if(wall[0][j]!='B'&&wall[1][j]!='B')
            poss=0;
        }
    }
    vvi arr,dup1,dup2;
    vi temp(n);
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(wall[i][j]=='B')
            temp[j]=1;
            else
            temp[j]=0;
        }
        arr.push_back(temp);
    }
    dup1=arr,dup2=arr;
    int c=0,r=0;
    if(poss && n==1)
    {
        cout<<"YES"<<'\n';
        return;
    }
    if(poss)
    {
        if(arr[0][0])
        {
            int step=0;
            while(exist(dup1,c,r))
            {
                step++;
            }
            if(step!=black)
            poss=0;
            else
            poss=1;
        }
        c=1,r=0;
        if(arr[1][0])
        {
            int step=0;
            while(exist(dup2,c,r))
            {
                step++;
            }
            if(step!=black)
            poss=0;
            else
            poss=1;
        }
    }
    cout<<(poss ? "YES":"NO")<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    cin>>t;
    while(t--)
    solve();
    return 0;
}