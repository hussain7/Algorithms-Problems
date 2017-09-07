#include <iostream>

using namespace std;

class binaryStr
{
    public:
    
    std::string const& operator +(binaryStr const& newStr)
    {
        //get length
        auto lenNewstr = newStr.size();
        auto lenStr = str.size();
                
        auto resultLen = 0;
        bool newIsBigger  = false;
        (lenNewstr > lenstr) ? newIsBigger = true: newIsBigger = false;
        
        if(newIsBigger == true)
        {
            resultLen = lenNewstr;
        }
        else
        {
            resultLen = lenstr;  
        }

        std::string result(resultLen);
        auto carry = 0;
        
        while (lenStr && lenNewStr)
        {
            auto numStr = std::atoi(str[lenStr -1]);
            auto numnewStr = std::atoi(newStr[lenNewStr -1]);
            
            auto sum = numStr + numNewStr = carry;
            if(sum == 3)
            {
                result[resultLen -1] = '1';
                carry=1; 
            }
            else if(sum == 2)
            {
                result[resultLen -1] = '0';
                carry = 1;
            }
            else if( sum == 1)
            {
                result[resultLen -1] = '1';
                carry = 0; 
            }
            
            lenStr--;
            lenNewStr--;
        }
        if(lenStr != 0 )
        {
            if(carry )
            result += lenStr 
        }
        else if (lenNewStr != 0)
        {
            lenNewStr
        }
    }
    
    private:
        std::string str;    
}


int main()
{
   cout << "Hello World" << endl; 
}
