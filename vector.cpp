#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> v;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t;
	    v.push_back(t);
	}
	vector <int> :: iterator it;

	for(it=v.begin();it!=v.end();it++)
	cout<<*it;
	return 0;
}