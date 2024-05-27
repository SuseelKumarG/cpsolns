#include<bits/stdc++.h>
using namespace std;
const unsigned long long MOD=1e9+7;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		int gap=0;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			if(i==0)
			continue;
			if(arr[i-1]==0 && arr[i]!=0)
			gap++;
		}
		int ans[2][gap];
        int s=0,count=0,zeroes=0;
        if(arr[0]==0)
        zeroes++;
        if(gap)
        {
        for(int i=1;i<n;i++)
        {
            if(arr[i]!=0)
            {
                ans[0][count]=arr[i]-arr[s];
                s=i;
                ans[1][count]=zeroes;
                zeroes=0;
                count++;
            }
            if(arr[i]==0)
            zeroes++;
        }
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<gap;j++)
            cout<<ans[i][j]<<' ';
            cout<<endl;
        }
        }
        else 
        cout<<-1<<endl;
	}
}