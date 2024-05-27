#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
        string s;
        cin>>s;
        char alph=s[0];
        int num=s[1]-'0';
        for(char beta='a';beta<='h';beta++)
        {
            if(beta==alph)
            continue;
            else
            cout<<beta<<num<<'\n';
        }
        for(int i=1;i<9;i++)
        {
            if(i==num)
            continue;
            else
            cout<<alph<<i<<'\n';
        }
    }
}