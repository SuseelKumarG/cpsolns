#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x1,x2,x3,x4,y1,y2,y3,y4;
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        int ans;
        if(x1==x2)
        {
            ans=abs(y1-y2);
        }
        else if(x1==x3)
        {
            ans=abs(y1-y3);
        }
        else
        ans=abs(y1-y4);
        ans*=ans;
        cout<<ans<<'\n';
    }
}