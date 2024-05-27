// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;
// typedef pair<int, int> pii;
// typedef pair<ll, ll> pll;
// typedef pair<string, string> pss;
// typedef vector<int> vi;
// typedef map<int,int> mi;
// typedef vector<vi> vvi;
// typedef vector<pii> vii;
// typedef vector<ll> vl;
// typedef vector<vl> vvl; 
// #define MAX 1000000007
// const  long long N=2*100010;
// vector<int>factrl(N);

// // void fact()
// // {
// //     factrl[0]=1;
// //     factrl[1]=1;
// //     for(int i=2;i<N;i++)
// //     factrl[i]=i*factrl[i-1];
// // }

// void solve()
// {
//     //hi
//     int n;
//     cin>>n;
//     float sum=0;
//     map<int,int> arr;
//     for(int i=0;i<n;i++)
//     {
//         int x;
//         cin>>x;
//         arr[x]++;
//         sum+=x;
//     }
//     float neededsum=(n-2)*(sum/(n-2)-(sum/n));
//     ll ans=0;
//     int tot=neededsum;
//     if(neededsum==tot)
//     {
//         for(auto it:arr)
//         {
//             int a=it.first;
//             int b=tot-a;
//             int x=arr[a];
//             int y=arr[b];
//             if(a==b)
//             {
//                 ans+=x*(x-1)/2;
//             }
//             else if(b>a)
//             ans+=x*y;
//         }
//     }
//     cout<<ans<<'\n';
// }



// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     // fact();
//     ll t;
//     cin>>t;
//     while(t--)
//     {
//         solve();
//     }
//     return 0;
// }
/*
first find mean of given integers and find the needed sum to get the answer if the needed sum is not integer then no pairs exist
if it is an integer then i am running a loop over the map(map is used to store the frequency) and checking that (neededsum - current element)
exists or not then i am checking if the current numuber and (neededsum - current element) are equal 


 1.If equal
 ans+=frequency*(frequency-1)/2
 {
    elementsc:   8 8 8 8
    indexes  :   1 2 3 4
    pairs are {(1,2),(1,3),(1,4),(2,3),(2,4),(3,4)}
 }

 2.if unequal
 ans+= product of frequency of both the elements
 also keeping the condition if(current numuber < (neededsum - current element) )
 to prevent adding of same pairs twice 
 {
    elements :   8 8 8 8
    indexes  :   1 2 3 4
    (1,2) & (2,1)are same but will be counted twice if not for the condition
 } 
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef map<int,int> mi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl; 
#define MAX 1000000007
const  long long N=2*100010;
vector<int>factrl(N);

// void fact()
// {
//     factrl[0]=1;
//     factrl[1]=1;
//     for(int i=2;i<N;i++)
//     factrl[i]=i*factrl[i-1];
// }

void solve()
{
    //hi
    int n;
    cin>>n;
    vector<int> a(n);
    map<int, int> cnt;
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
        sum+=a[i];
    }
    // long long sum = accumulate(a.begin(), a.end(), 0LL);
    if ((2 * sum) % n != 0) {
      cout<<0<<'\n';
      return;
    }
    long long need = (2 * sum) / n;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      int a1 = a[i];
      int a2 = need - a1;
      if (cnt.find(a2)!=cnt.end()) ans += cnt[a2];
      if (a1 == a2) ans -= 1;
      }
    cout<<ans/2<<'\n';
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // fact();
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}