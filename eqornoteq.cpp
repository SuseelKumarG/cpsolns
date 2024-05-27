#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n=0;
        for(auto it:s)
        {
            if(it=='N')
            n++;
        }
        cout<<(n==1 ? "NO\n" : "YES\n" );
    }
}