//SAMARTH SHARMA 2020A3PS0615H

#include <bits/stdc++.h>
using namespace std;


void insertion_sort(vector<int>& v)
{
    for(int j=1; j<v.size();j++)
    {
      int key = v[j];
      int i = j-1;

      while(i >= 0 && v[i] > key)
      {
         v[i+1] = v[i];
         i--;
      }
      v[i+1] = key;
    }
}

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

		//USING INSERTION SORT HERE
		insertion_sort(v);

		//CALCULATION
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