
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

void negative(std::vector<int>& input)
{
    int lastnegIndex = -1;

    for(int i=0; i< input.size() -1 ; i++)
    {
        if(input[i] < 0 && input[i+1] >= 0 )
        {
            lastnegIndex = i;
            // swap
            int temp = input[lastnegIndex];
            input[lastnegIndex] = input[i+1];
            input[i+1] = temp;
            // update the last index
            lastnegIndex++;
        }
    }
}

int main() {
    int narray = 5;

    std::vector<int> input;
    input.push_back(-3);
    input.push_back(0);
    input.push_back(1);
    input.push_back(-2);
    input.push_back(-4);

    std::cout<<" Before "<<std::endl;
    for(auto element:input)
    {
        std::cout<<" "<<element;
    }
    std::cout<<std::endl;
    negative(input);
    std::cout<<" After "<<std::endl;
    for(auto element:input)
    {
        std::cout<<" "<<element;
    }
    return 0;
}
