#include <iostream>

using namespace std;

//subarray with zero sum Exists
bool subArrayExists(int arr[], int n)
{
	unordered_map<int,bool> sumMap;

	// Traverse throught array and store prefix sums
	int sum = 0;
	for (int i = 0 ; i < n ; i++)
	{
		sum += arr[i];

		// If prefix sum is 0 or it is already present
		if (sum == 0 || sumMap[sum] == true)
			return true;

		sumMap[sum] = true;
	}
	return false;
}

// legth of the largest subarray with zero sum
int lenghtofLargestSubarray(int a[], int n)
{
    unordered_map<int, int> sumMap;
    int lastSum = 0, maxDiff=0;
    for(auto i=0;i<n;i++)
    {
        lastSum+= a[i];
        if(sumMap.find(lastSum) != sumMap.end() || lastSum == 0)
        {
            auto currentDiff = 0;
            if(lastSum != 0)
                { 
                    auto index = sumMap[lastSum];
                    currentDiff = i - index;
                }
                else
                {
                    currentDiff = i+1; 
                }
            if(currentDiff > maxDiff)
                maxDiff = currentDiff;
        }
        else
        {
            sumMap[lastSum] = i;
        }
    }
    
    return maxDiff;
    
}


// Driver code
int main()
{
	int arr[] = {4, -2, 3, -2, 1, 6,0,0,0,0,0};
	int n = sizeof(arr)/sizeof(arr[0]);
	auto max = lenghtofLargestSubarray(arr,n);
    std::cout<< "Maximum Value "<<max;
	return 0;
}
