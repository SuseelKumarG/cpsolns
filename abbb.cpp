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
        stack<char>check;
        for(auto it : s)
        {
            if(it=='A')
            check.push(it);
            else
            {
                if(!check.empty())
                {
                    check.pop();
                }
                else
                check.push(it);
            }
        }
        cout<<check.size()<<'\n';
    }
}