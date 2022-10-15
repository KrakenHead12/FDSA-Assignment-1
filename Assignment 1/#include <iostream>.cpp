#include <iostream>
using namespace std;

// check if a a given array is sorted using recursion.
bool isSortedRecursive(int *arr, int n, int idx)
{
    // base case
    if (idx >= n)
        return true;

    // if item at current index is smaller than item at immediate-left,
    // we should return false
    if (arr[idx]>arr[idx+1])
    {
        return false;
    }
    else if(arr[idx]<=arr[idx+1])	
    {
	//return isSortedRecursive(arr,n,idx+1); 
	return true; 
    }

    isSortedRecursive(arr,n,idx+1);
    // ……………………………………………………………… TASK 2 ……………………………………………………………………………
    // similarly compare current index with the item at immediate-right
    // and decide the return value.

    //return isSortedRecursive(arr,n,idx+1);
    // ……………………………………………………………… TASK 3 …………………………………………………………………………
    // recursively solve for the remaining items.
}

bool isSorted(int *arr, int n)
{
    return isSortedRecursive(arr, n, 1);
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int *arr = new int[n];
    cout << "Enter " << n << " elements:";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if (isSorted(arr, n))
        cout << "SORTED" << endl;
    else
        cout << "NOT SORTED" << endl;

    return 0;
}