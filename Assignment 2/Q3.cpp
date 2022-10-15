#include<bits/stdc++.h>
using namespace std;

vector<int> func(vector<int> &v)
{
	int n=v.size();
	stack<int> s;
	vector<int> ans(n,-1);
	s.push(v[0]);

	for(int i=0;i<n;i++)
	{
		while(!s.empty() && v[i]>v[s.top()])
		{
			ans[s.top()]=v[i];
			s.pop();
		}
		s.push(v[i]);
	}
	return ans;
}
int main()
{
	int n;
	cin >> n;
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		int e;
		cin >> e;
		v.push_back(e);
	}

	vector<int> ans=func(v);
	for(int i=0;i<n;i++)
	cout << ans[i] << " ";
}