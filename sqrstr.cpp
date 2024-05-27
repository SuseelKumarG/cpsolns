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
        int size=s.length();
        bool poss=1;
        if(size & 1)
        poss=0;
        else
        {
            for(int i=0;i<size/2 && poss;i++)
            {
                if(s[i]!=s[i+size/2])
                poss=0;
            }
        }
        cout<<(poss ? "YES\n" : "NO\n" );
    }
}