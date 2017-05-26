#include <iostream>
#include <vector>
using namespace std;


int findMissingNumber(std::vector<int> const& arr1, std::vector<int> const& arr2)
{
    auto number=0;
    for(auto i:arr1)
    {
        number=number^i;
    }     
    for(auto j:arr2)
    {
        number=number^j;
    }   
    
    return number;
}

int main() {
	//code
	int a[] = {12, 10, 15, 23, 11, 30}; 
    int b[] = {15, 12, 23, 11, 30};
    std::vector<int> vecA(a, a+6);
    std::vector<int> vecB(b, b+5);
    std::cout<< "Missing Number " <<findMissingNumber(vecA,vecB);
	return 0;
}
