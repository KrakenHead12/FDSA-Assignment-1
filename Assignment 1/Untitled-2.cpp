#include <bits/stdc++.h>
using namespace std;
class Timer
{
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> startTimePoint;
    std::chrono::time_point<std::chrono::high_resolution_clock> endTimePoint;
    double getTimeDifference();

public:
    Timer();
    void start();
    void stop();
    double getDurationInSeconds();
    double getDurationInMilliSeconds();
    double getDurationInMicroSeconds();
};

Timer::Timer() {}

void Timer::start()
{
    startTimePoint = std::chrono::high_resolution_clock::now();
}

void Timer::stop()
{
    endTimePoint = std::chrono::high_resolution_clock::now();
}

double Timer::getTimeDifference()
{
    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(startTimePoint).time_since_epoch().count();
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();
    return end - start;
}

double Timer::getDurationInSeconds()
{
    return getDurationInMilliSeconds() * 0.001; // in seconds
}

double Timer::getDurationInMilliSeconds()
{
    return getTimeDifference() * 0.001; // in milli seconds
}

double Timer::getDurationInMicroSeconds()
{
    return getTimeDifference(); // in micro-seconds
}


int binarySearchRecursive(int *arr, int low, int high, int target)
{
    // base case
    if (low > high)
        return -1;

    // find middle index
    int mid = low + ((high - low) >> 1);

    // if the target item is less than the item at mid index,
    // it means the target item should be present in the left half of the
    // array, so recur for left-half ……………………………………… TASK 4 ………………………………
    if(target<arr[mid])
    {
	return binarySearchRecursive(arr,low,mid-1,target);    
    }
    

    // similarly, if the target item is greater than the item at mid index,
    // recur for the right-half ………………………………………………… TASK 5 ……………………………………
    if(target>arr[mid])
    {
	return binarySearchRecursive(arr,mid+1,high,target);
    }
   

    // return the middle index
    //if(target==arr[mid])
    //{
    //	return mid;    
    //}
    return mid;
    
}
int binarySearch(int *arr, int n, int target)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);
        if (target == arr[mid])
            return mid;
        if (target < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int linearSearch(int *arr, int n, int target)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == target)
            return i;
    return -1;
}

int main()
{
    int n = 10000000;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
        arr[i] = i + 1;

    Timer timer; // initialize timer class object.

    timer.start(); // start timer.

    linearSearch(arr, n, n); // call to linear search

    timer.stop(); // stop timer.

    // function to get time in milli seconds
    double milliSecs = timer.getDurationInMilliSeconds();

    cout << "Linear Search took: " << milliSecs << " ms." << endl;

    timer.start(); // start timer.

    binarySearch(arr, n, n); // call to binary search

    timer.stop(); // stop timer.

    // function to get time in milli seconds
    milliSecs = timer.getDurationInMilliSeconds();

    cout << "Binary Search took: " << milliSecs << " ms." << endl;

    /**************************************************************
     * Utility code to test Recusrive Binary Search Functionality *
     **************************************************************/
    int m;
    cout << "Enter the size of the array: ";
    cin >> m;
    int *a = new int[m];
    cout << "Enter a sorted list of " << m << " elements:" << endl;
    for (int i = 0; i < m; i++)
        cin >> a[i];
    int target;
    cout << "Enter the target item to search for: ";
    cin >> target;
    int idx = binarySearchRecursive(a, 0, m - 1, target);
    if (idx > -1)
        cout << target << " FOUND at index " << idx << endl;
    else
        cout << "NOT FOUND" << endl;
}