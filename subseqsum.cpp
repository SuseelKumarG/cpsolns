#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        vector<int>inp(7);
        for(int i=0;i<7;i++)
        cin>>inp[i];
        cout<<inp[0]<<' '<<inp[1]<<' '<<inp[6]-inp[0]-inp[1]<<'\n';
    }
}