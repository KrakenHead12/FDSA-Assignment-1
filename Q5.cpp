//SAMARTH SHARMA 2020A3PS0615H
#include <bits/stdc++.h>
using namespace std;

void swap(int i,int j)
{
	int t=i;
	i=j;
	j=t;
}
int main()
{
    int n; cin>>n;
    vector<int> v;
  
    for(int i=0;i<n;i++)
    {
	    int t;
	    cin>>t;
	    v.push_back(t);
    }
	int ans=0;
    for(int i=0;i<n;i++)
    {
        int idx=i;
        for(int j=i+1;j<n;j++){
            if(v[j]>v[idx]) 
            idx = j;
        }
        if(idx != i){
            swap(v[i],v[idx]);
            ans++;
        }
    }
    cout<<ans<<endl;

    return 0;
}