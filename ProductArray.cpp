/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <vector>
#include <iostream>
#include <algorithm>

long int product(std::vector<int> const& arr, std::vector<long int>& result)
{
    long int product=1;
    for (auto element: arr)
    {
        product = product*element;
    }
    
    for (auto i=0; i<arr.size(); ++i)
    {
        if(arr[i] == 0)
        {
            result.push_back(0);
        }
        else
        {
            result.push_back(product/arr[i]);
        }

    }
}

int main()
{
    std::vector<int> arr{2,3,4,566,7,1};
    std::vector<long int >result;
    product(arr,result);
    auto lambda = [](long int i ){std::cout<<i<<std::endl;};
    std::for_each(result.begin(), result.end(),lambda);
}
