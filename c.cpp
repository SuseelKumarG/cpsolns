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
    string s;
    cin>>s;
    vector<string>arr(4);
    arr[0]="dream";
    arr[1]="dreamer";
    arr[2]="eraser";
    arr[3]="erase";
    bool poss=1;
    for(int i=0;i<s.length() && poss;)
    {
        if(s[i]=='d' || s[i]=='e')
        {
            if(s[i]=='d')
            {
                for(int j=0;j<arr[0].length();j++)
                {
                    if(s[i++]!=arr[0][j])
                    poss=0;
                }
                if(s[i]=='e' && s[i+1]=='r' && s[i+2]!='a')
                i+=2;
            }
            else
            {
                for(int j=0;j<arr[3].length();j++)
                {
                    if(s[i++]!=arr[3][j])
                    poss=0;
                }
                if(s[i]=='r' && s[i+1]!='a')
                i+=1;
            }
        }
        else
        poss=0;
    }
    cout<< (poss ? "YES\n":"NO\n"); 
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // fact();
    // ll t;
    // cin>>t;
    // while(t--)
    {
        solve();
    }
    return 0;
}