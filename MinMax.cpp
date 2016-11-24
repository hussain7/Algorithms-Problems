
#include "stdafx.h"

#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;



// player is max and start first
int minimax(int height, int depth, int index , bool isMax, std::vector<int> const& score)
{
    // terminating condition
    if(depth == height)
        return score[index];

    // check in the left and right .. where to move.
    if(isMax)
    {
        return std::max(minimax(height, depth+1, 2*index, false, score), minimax(height, depth+1, 2*index+1, false, score));
    }
    else
    {
        return std::min(minimax(height, depth+1, 2*index, true, score), minimax(height, depth+1, 2*index+1, true, score));
    }
}

int main() 
{
    int arr[] = {3, 5, 2, 9, 12, 5, 23, 23};
    int n = sizeof(arr)/sizeof(arr[0]);
    std::vector<int> score(arr , arr+n);
    int height = n ==1 ? 0 : (log(n)/log(2));
    // starting with the max player
    auto scoreWin  = minimax(height, 0, 0, true, score);
    std::cout<<scoreWin<<std::endl;
    return 0;
}