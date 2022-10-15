#include <bits/stdc++.h>
using namespace std;
bool func(int n, queue<int>& q)
{
    stack<int> st;
    int i=1,j;
    
 
    while (!q.empty()) {
        j=q.front();
        q.pop();
 
        if (j == i)
            i++;
        else {
            if (st.empty()) {
                st.push(j);
            }
            else if (!st.empty() && st.top() < j) {
                return false;
            }
            else
                st.push(j);
        }
        while (!st.empty() && st.top() == i) {
            st.pop();
            i++;
        }
    }

    if (i - 1 == n && st.empty())
        return true;
 
    return false;
}
 
int main()
{
    queue<int> q;
    q.push(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
 
    int n = q.size();
 
    if(func(n,q))
    {
	    cout << "yes" <<endl;
    }
    else
    {
	    cout << "no" << endl;
    }
 
    return 0;
}