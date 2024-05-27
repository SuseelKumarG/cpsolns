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
        int n,sum=0,count=1e5,maxm=0;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
            maxm=(maxm<arr[i])? arr[i]:maxm;
        }
        for(int i=1;i<=n;i++)
        {
            if(!(sum%i))
            {
                int currsum=0,destinedsum=sum/i,currcount=0,ind=0;
                bool sucessful=1;
                for(int j=0;j<n && destinedsum>=maxm;j++)
                {
                    currsum+=arr[j];
                    if(currsum==destinedsum)
                    {
                        currsum=0;
                        currcount+=(j-ind);
                        ind=j+1;
                    }
                    if(currsum>destinedsum)
                    {
                        sucessful=0;
                        break;
                    }
                }
                if(sucessful)
                {
                    count=(count<currcount)? count:currcount;
                }
            }
        }
        cout<<count<<'\n';
    }
}