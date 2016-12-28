#include "stdafx.h"
#include <iostream>
#include <algorithm>

using namespace std;

void createSegmentTree(int tree[], int input[], int indexTree, int low , int high)
{
    if(low >= high)
    {
    // assign tree leaves from input array
        tree[indexTree] = input[low];
    }
    else
    {
        int mid = (low + high)/2;
        // call for left and right divisions
        createSegmentTree(tree, input, 2*indexTree , low, mid);
        createSegmentTree(tree, input, 2*indexTree + 1, mid+1, high);
        tree[indexTree] = std::min(tree[2*indexTree],tree[2*indexTree + 1]);
    }
}

int main()
{
    int input[10] = {2,3,5,18,211,1};
    // create output array tree
    auto size = sizeof(input)/sizeof(input[0]);
    auto tree = new int[2*size - 1];
    createSegmentTree(tree, input, 0, 0, size-1);
    return 0;
}
