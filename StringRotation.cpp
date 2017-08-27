// Example program
#include <iostream>
#include <string>
using namespace std;

class stringOperations
{
    public:
    
    stringOperations(std::string const& baseStringArg): baseString(baseStringArg)
    {}
    
    static int findIndex(string const& testString, char ch )
    {
        auto found = testString.find(ch);
        if(found != std::string::npos)
        {
            return found;
        }
        else
        {   
            return -1;
            
        }
    }
    
    bool checkRotate(string const& newString)
    {
        auto length1 = newString.size();
        auto length2 = baseString.size();
        
        if(length1 != length2)
        return false;
        
        // otherwise capture index
        auto index = findIndex( baseString, newString[0]);
        
        std::cout<< "first index "<<index<<std::endl;
        // and iterate to check the same order        
        auto tranformedIndex = index;
        for(auto i=0; i<length1; ++i)
        {            
            if(tranformedIndex >= length1)
            {
               tranformedIndex = length1 - tranformedIndex; 
            }
            std::cout<< "index "<<i<<" base str ch " << baseString[tranformedIndex] <<" new string ch "<<newString[i] <<std::endl;
            if(baseString[tranformedIndex] != newString[i])
                {
                    return false;
                }
            tranformedIndex++;    
        }
        return true;
    }
    
    private:
        std::string baseString;
    
};

int main()
{
  std::string str1 = "ABCD";
  std::string str2 = "CABD";
  stringOperations operate(str1);
  std::cout <<"Same or not "<< operate.checkRotate(str2)<<std::endl;
}

