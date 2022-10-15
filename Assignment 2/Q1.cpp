#include <bits/stdc++.h>
#include "timer.h"
using namespace std;


bool func(vector<int>&v,int i,int j,int k)
{
	if(i==j)
	return false;

	if(v[i]+v[j]==k)
	{
		return true;
	}
	
	if(v[i]+v[j]>=k)
	{
		return func(v,i,j-1,k);
	}
	
	return func(v,i+1,j,k);
}

int main()
{
	int t; cin >>t;
	while(t--)
	{
		Timer timer;
		int n,k;
		cin >> n >> k;
		vector<int>v;
		timer.start();
		//ENTER SORTED ELEMENTS
		for(int i=0;i<n;i++)
		{
			int e;
			cin >> e;
			v.push_back(e);
		}

		cout << func(v,0,n-1,k) << endl;
		timer.stop();
		double time=timer.getDurationInMilliSeconds();
		cout << "Execution Time is" << time << "ms" <<endl;
		
	}
}