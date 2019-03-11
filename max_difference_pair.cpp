/******************************************************************************

Given a array of numbers representing the stock prices of a company in chronological order
, write a function that calculates the maximum profit
you could have made from buying and selling that stock once. You must buy before you can sell it.

For example, given [9, 11, 8, 5, 7, 10], you should return 5, since you could buy the stock at 5 dollars and sell it at 10 dollars.

# logic is to keep global minimum number, result and maximum difference so far . result may not be global minimum. 

https://stackoverflow.com/questions/35246177/find-the-max-difference-pair-in-the-array

*******************************************************************************/


#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int highest_stock(std::vector<int> const& stock_arr)
{
    int min=INT_MAX, max_diff = 0, result=-1;
    
    for (auto const& num : stock_arr)
    {
        if(min >= num)
        {
            min = num;
        }
        
        if(num - min > max_diff)
        {
            result = min;
        }
    }
    
    return result;
}

int main()
{
    std::vector<int> arr = {9, 11, 8, 5, 7, 10};
    std::cout<< highest_stock(arr);
    return 0;
}
