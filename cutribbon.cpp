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

vi check(4010,-1);

int soln(int n,int a,int b,int c)
{
    if(n==0)
    return 0;
    if(n<0)
    return INT_MIN;
    if(check[n]!=-1)
    return check[n];
    check[n]=1+max(soln(n-a,a,b,c),max(soln(n-b,a,b,c),soln(n-c,a,b,c)));
    return check[n];
}

void solve()
{
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    cout<<soln(n,a,b,c);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;
// typedef pair<int, int> pii;
// typedef pair<ll, ll> pll;
// typedef pair<string, string> pss;
// typedef vector<int> vi;
// typedef vector<vi> vvi;
// typedef vector<pii> vii;
// typedef vector<ll> vl;
// typedef vector<vl> vvl; 
// #define MAX 1000000007


// void solve()
// {
//     int n,a,b,c;
//     cin>>n>>a>>b>>c;
//     if(a>b)
//     swap(a,b);
//     if(a>c)
//     swap(a,c);
//     if(c<b)
//     swap(b,c);
//     int maxm=-1;
//     for(int j=1;j<=4000;j++)
//     {
//         for(int i=1;i<=4000;i++)
//         {
//             if(n>=a*i+b*j)
//             {
//                 if(!((n-a*i-b*j)%c))
//                 {
//                     int k=(n-a*i-b*j)/c;
//                     int temp=i+j+k;
//                     maxm=max(maxm,temp);
//                 }
//             }
//         }
//     }
//     cout<<maxm<<'\n';
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     solve();
//     return 0;
// }