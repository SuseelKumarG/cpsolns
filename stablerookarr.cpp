#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        if(k>(n+1)/2)
            cout<<-1<<'\n';
        else
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(j==i && k && !(j & 1))
                    {
                        cout<<'R';
                        k--;
                    }
                    else
                    cout<<'.';
                }
                cout<<'\n';
            }
        }
    }
}