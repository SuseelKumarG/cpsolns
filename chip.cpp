#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        long long h,w,xa,xb,ya,yb;
        cin>>h>>w>>xa>>ya>>xb>>yb;
        if(xa>=xb)
        {
            cout<<"DRAW\n";
            continue;
        }
        else if(abs(xa-xb)<abs(ya-yb))
        {
            cout<<"DRAW\n";
            continue;
        }
        else
        {
            long long len=sqrt((abs(xa-xb)*abs(xa-xb)+abs(ya-yb)*abs(ya-yb))/2);
            // len/=sqrt(2);
            if(len&1)
            cout<<"BOB\n";
            else
            cout<<"ALICE\n";
        }
    }
}