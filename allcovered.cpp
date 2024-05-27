#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        string s;
        cin>>n>>k>>s;
        vector<int> arr(27);
        for(auto it:s)
            arr[it-'a'+1]++;
        bool poss=1;
        for(int i=0;i<27;i++)
        {
            if(arr[i])
            {
                if(i<=k)
                {
                    if(arr[i]<n)
                    poss=0;
                }
                if(arr[i]<n-1)
                poss=0;
            }
        }
        
    }
}