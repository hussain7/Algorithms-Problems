
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int first_positive_missing(std::vector<int>& arr)
{
    std::sort(arr.begin(),arr.end());
    
    int expected = 0;
    for (auto i=0; i<arr.size();++i)
    {
        if(arr[i] > 0 && arr[i] != 1)
        {
            if(arr[i] - arr[i-1] != 1)
            {
                if(arr[i-1] <0)
                {
                    return 1;
                }
                else
                {
                     return arr[i-1] +1;
                }

            }
        }
    }
    return 0;
}


int main()
{
    
    std::vector<int> arr = {3,4,-1,1,2,6};
    std::cout<<first_positive_missing(arr);
    
    return 0;
}
