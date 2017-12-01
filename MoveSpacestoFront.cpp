// Example program
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

//2 X 7 X X 10 X
// 5 8 12 14
const int NA=-1;

void movetoEnd(std::vector<int>& v )
{
    int j=v.size()-1;
    for(int i=v.size()-1; i>=0;--i )
    {
        if(v[i] != NA)
        {
            v[j] = v[i];
            j--;
            v[i]=NA;
        }
    }
}

void print(std::vector<int> const& v)
{
    auto print = [](int i ){ std::cout<<i<<" ";};
    std::for_each(v.begin(),v.end(),print);
}

int main()
{
    std::vector<int> v{2,NA,7,NA,NA,10,NA};
    movetoEnd(v);
    print(v);
    
}
