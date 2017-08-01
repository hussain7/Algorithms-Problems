#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

const std::string binary(int num)
{
std::string result;

while(num)
	{
		result.append(to_string(num%2));
		num=num/2;
	}
std::reverse(result.begin(),result.end());
return result;
}
int main(void)
{
    std::cout <<"reverse "<<binary(12)<<std::endl;
}
