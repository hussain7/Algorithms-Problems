// C++ program to print all subarrays
// in the array which has sum 0
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Function to print all subarrays in the array which
// has sum 0
vector< pair<int, int> > findSubArrays(int arr[], int n)
{
	std::unordered_map<int,bool> sumMap;
	vector< pair<int, int> >  subarrays;
	int sum=0;
	auto lastindex=-1;
	for(auto i=0; i<n; ++i)
	{
	    sum = sum+arr[i];
	    if(sum == 0 || sumMap[sum] )
	    {
	       subarrays.push_back(std::make_pair(lastindex+1, i)); 
	    }
	    else
	    {
	        sumMap[sum]=true;
	    }
	
	}
	
	return subarrays;
}

// Utility function to print all subarrays with sum 0
void print(vector<pair<int, int>> out)
{
	for (auto it = out.begin(); it != out.end(); it++)
		cout << "Subarray found from Index " <<
			it->first << " to " << it->second << endl;
}

// Driver code
int main()
{
	int arr[] = {6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7};
	int n = sizeof(arr)/sizeof(arr[0]);

	vector<pair<int, int> > out = findSubArrays(arr, n);

	// if we didn’t find any subarray with 0 sum,
	// then subarray doesn’t exists
	if (out.size() == 0)
		cout << "No subarray exists";
	else
		print(out);

	return 0;
}
