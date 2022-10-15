//SAMARTH SHARMA 2020A3PS0615H

#include <bits/stdc++.h>
using namespace std;

void helper(int n,int open,int close,string str,vector<string> &ans)
{
        if(open > n)
            return;
        if(open == n && close == n)
        {
            ans.push_back(str);
            return;
        }
        
        helper(n,open+1,close,str+'(',ans);
        
        if(open > close)
            helper(n,open,close+1,str+')',ans);
        
}

int main() 
{
	int t;cin>>t;
	while(t--)
	{
		int n;
		cin >> n;
        	string str = "";
        	vector<string> ans;
        	helper(n,0,0,str,ans);
		for(int i=0;i<ans.size();i++)
		{
			cout << ans[i] <<endl ;
		}
		cout << endl;

	}
	
	return 0;
        
}
