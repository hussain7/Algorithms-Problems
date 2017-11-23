// Example program
#include <iostream>
#include <string>
#include <cmath>

// string to number 

int stringtoInt(const std::string& input)
{
    //auto length = input.length(); 
    std::cout<<length<<std::endl;
    auto t=0,result=0;
    for(int i=input.length()-1; i>=0; --i)
    {
        std::cout<<"i "<<i<<std::endl;
        int number = static_cast<int>(input[i]- 48);
        std::cout<<number<<std::endl;
        result = result+number*std::pow(10,t++);
        
    }
    return result;
}

int main()
{

  std::cout << "Hello, " <<stringtoInt("12345");
}
