#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        multiset<int> s;
        int n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            s.insert(x);
        }
        long long sum=0;
        while (k--)
        {
        sum+=*(s.begin());
        int l=*(s.begin());
        s.erase(s.begin());
        s.insert(l/2);
        }
        cout<<sum<<endl;
    }
}