
#include <bits/stdc++.h>
using namespace std;
int main() {
	int test;
	cin>>test;
	unordered_set<long long> st;
	for(long long i=1;i*i*i <= 1000000000000;i++)
	{
	    st.insert(i*i*i);
	}
	while(test--)
	{
	    long long x; cin>>x;
	    bool flag = 0;
	    for(long long i=1;i*i*i<=x;i++)
	    {
	        if(st.count(x-i*i*i)) {flag=1; break;}
	    }
	    if(flag) cout<<"YES\n";
	    else cout<<"NO\n";
	}
	return 0;
}
