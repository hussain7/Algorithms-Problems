#include <iostream>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

//a1,a2,a3,a4...an, b1,b2,b3,b4....bn
//convert into a1,b1,a2,b2,a3,b3... 

void convert(std::vector<int>& arr, int start , int end)
{
    //swap upto n/2 numbers of each sides
    // to become a1,a2,b1,b2,a3,a4,b3,b4
    
    auto n = arr.size()/2;
    std::vector<int> temp(n/2);
    memcpy(arr.data()+n/2 + 1, temp.data(), n/2);
    memcpy(arr.data()+n/2 + 1, arr.data()+n + 1, n/2 );
    memcpy(temp.data(), arr.data()+n/2 + 1, n/2);

    // dont split if total lenght is only 4 since it has already achieved
    if(n == 2)
        return; 
    //split the vector
    auto mid = (start+end)/2;
    convert(arr,start,mid);
    convert(arr, mid+1, end);
}

void print(int *arr, int n)
{
    for(auto i=0; i<n ;++i)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}

int main() {
	//code
	int a1[16] = {1,2,4,5,6,7,7,8,13,22,83,33,63,45,71,88};

    std::vector<int> vec1(a1,a1+16);
    
    convert(vec1,0,16);
    print(vec1.data(),16);
    
    
	return 0;
}
