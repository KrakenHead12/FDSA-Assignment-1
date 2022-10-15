#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,k;
		cin >> n >> k;
		vector<int> v;
		//TAKING INPUT IN VECTOR
		for(int i=0;i<n;i++)
		{
			int e;
			cin >> e;
			v.push_back(e);
		}

		sort(v.begin(),v.end());
		int count=0;
		for(int i=0;i<n;i++)
		{
			if(v[i]<=k)
			{
				k-=v[i];
				count++;
			}
			else
			{
				break;
			}
		}
		cout << count << endl;


	}
	return 0;
}