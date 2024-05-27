#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s,t;
        cin>>s>>t;
        sort(s.begin(),s.end());
        // string ans=s;
        if(t=="abc" && s[0]=='a')
        {
            string rem;
            string a,c;
            for(auto it:s)
            {
                if(it=='a')
                a.push_back('a');
                else if(it=='c')
                c.push_back('c');
                else
                rem.push_back(it);
            }
            sort(rem.begin(),rem.end());
                s=a+c+rem;
        }
        cout<<s<<'\n';
    }
}