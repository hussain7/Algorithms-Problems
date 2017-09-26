#include <iostream>
#include <math.h>
using namespace std;

int convert(std::string const& str)
{
    int result=0;
    auto i=0;
    auto len = str.length();
    for(auto i=0;i<len;i++)
    {
        auto val = (int)str[len-1 - i] - 48;
        result += val*pow(10,i);
    }
    
    return result;
}

int main()
{
   cout << "Strint to INT " << convert("12235")<<endl; 
   
}
