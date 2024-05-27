#include<iostream>
using namespace std;
int main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
        int x;
        cin>>x;
        string s;
        cin>>s;
        int c1=0,c0=s.length();
        // cout<<c0<<' ';
        for(auto it:s)
        {
            if(it-'0')
            c1++;
        }
        c0-=c1;
        if(c0)
        cout<<"YES\n";
        else
        cout<<"NO\n";
    }
}