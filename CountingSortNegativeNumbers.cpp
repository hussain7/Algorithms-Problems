#include "stdafx.h"

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <iostream>
using namespace std;

#define RANGE 10
void countingSort(int const arr[], int output[], int n)
{
    std::vector<int> countArr(RANGE + n);

    // iterate the input array first
    for(auto i=0;i<n;i++)
    {
        countArr[arr[i]]++;
    }
    // add the counts to get relative positions
    for(auto i = 1;i<n;i++)
    {
        countArr[i] = countArr[i-1] + countArr[i];
    }

    // sort into the output
    for(auto i=0;i<n;i++)
    {
        // input value will move into the position of count array in output arr
        if(countArr[arr[i]] > 0)
        {
            output[countArr[arr[i]] -1] = arr[i];
            countArr[arr[i]]--;
        }
    }
}
int main()
{

    int arr[] = {4,3,1,5,1,2,3};
    int n= sizeof(arr)/sizeof(arr[0]);
    int output[sizeof(arr)/sizeof(arr[0])] = {0};
    countingSort(arr, output, n);

    for(auto i:output)
    std::cout<<" ---"<<i;
    return 0;
}
