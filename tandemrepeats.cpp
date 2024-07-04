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
typedef vector<ull> vul;
typedef vector<vl> vvl; 
typedef vector<pll> vll; 
typedef vector<bool> vb;
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

bool poss(string &s,int k)
{
    int n=s.length();
    for(int i=0;i<=n-k;i++)
    {
        int b=i,e=i+k/2;
        bool easy=1;
        for(int j=0;j<k/2;j++)
        {
            // cout<<s[b+j]<<' '<<s[e+j]<<'\n';
            if(s[b+j]!=s[e+j]&&s[b+j]!='?'&&s[e+j]!='?')
            {
                i+=j;
                easy=0;
                break;
            }
        }
        if(easy)
        return 1;
        // cout<<'\n';
    }
    return 0;
}

void solve()
{
    string s;
    cin>>s;
    int n=s.length();
    int ans=0;
    set<char>x;
    for(auto it:s)
    x.insert(it);
    if(x.size()==1)
    {if(n&1)
    n--;
    cout<<n<<'\n';
    return;
    }
    // for (int len = 2; len <= n; len+=2) 
    // {    
    //     // Pick ending point
    //     for (int i = 0; i <= n - len; i++) 
    //     {
    //         //  Print characters from current
    //         // starting point to current ending
    //         // point. 
    //         int b=i; 
    //         int e = i + len - 1;            
    //         // for (int k = b; k <= e; k++) 
    //         //     cout << s[k];
             
    //         // cout << '\n';
    //         int l=e-b+1;
    //         l>>=1;
    //         bool poss=1;
    //         int b=b,se=b+l;
    //         for(int j=0;j<l&&poss;j++)
    //         {
    //             if(s[fi+j]!=s[se+j]&&s[fi+j]!='?'&&s[se+j]!='?')
    //             poss=0;
    //         }
    //         if(poss)
    //         ans=max(ans,l<<1);
    //         // cout<<l<<'\n';
    //     }
    // }
    // for (int i = 0; i < n; i++) {
    //     string sub;
    //     // Second loop is generating sub-string
    //     for (int j = i; j < n; j++) {
    //         sub.push_back(s[j]);
    //         // cout << sub << endl;

    //         int l=sub.length();
    //         if(l&1)
    //         continue;
    //         bool poss=1;
    //         l>>=1;
    //         int fi=i;
    //         int se=i+l;
    //         for(int j=0;j<l;j++)
    //         {
    //             if(s[fi+j]!=s[se+j]&&s[fi+j]!='?'&&s[se+j]!='?')
    //             {poss=0;
    //             break;}
    //         }
    //         if(poss)
    //         ans=max(ans,l<<1);
    //     }
    // }
    if(n&1)
    n--;
    for(int k=n;k>0;k-=2)
    {
        // for(int i=0;i<=n-2*k;i++)
        // {
        //     int b=i,e=i+k;
        //     bool easy=1;
        //     for(int j=0;j<k;j++)
        //     {
        //         // cout<<s[b+j]<<' '<<s[e+j]<<'\n';
        //         if(s[b+j]!=s[e+j]&&s[b+j]!='?'&&s[e+j]!='?')
        //         {
        //             i+=j;
        //             easy=0;
        //             break;
        //         }
        //     }
        //     if(easy)
        //     {
        //         ans=k<<1;
        //         goto A;
        //     }
        //     // cout<<'\n';
        // }
        if(poss(s,k))
        {
            ans=k;
            goto A;
        }
    }
    // poss(s,6);
    A:
    cout<<ans<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    cin>>t;
    while(t--)
    {
        // cout<<t<<0<<'\n';
        // cout<<t<<'\n';
        solve();
    }
    return 0;
}