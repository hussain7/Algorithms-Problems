#include <iostream>
using namespace std;


std::string  fizzNumber(int number)
{
    bool numThree = false;
    bool numFive = false;
    
    std::string output;
    if(number%3 == 0)
        numThree = true;
    
    if(number%5 == 0)
        numFive = true;
    
    if(numFive == true && numThree == true)
    {
        output = "FizzBuzz";
    }
    else if(numFive == true)
    {
        output = "Buzz";
    }
    else if(numThree == true)
    {
        output = "Fizz";
    }
    else
    {
        output = std::to_string(number);
    }
    
    return output;
    
}

int main()
{
    auto n=0;
    cin>>n;
    auto i = 0;
    
    int number;
    while( i < n)
    {
        cin>>number;
        for(int p=1; p<=number;++p)
            cout<<fizzNumber(p)<<std::endl;
        ++i; 
    }
    
    return 0;
}
