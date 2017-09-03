// Example program
#include <iostream>
#include <string>
#include <map>

struct Dictionary
{
    std::map<int, std::string> dict;
    
    Dictionary()
    {
        dict[0] = "";
        dict[1] = "One";
        dict[2] = "Two";
        dict[3] = "Three";
        dict[4] = "Four";
        dict[5] = "Five";
        dict[6] = "Six";
        dict[7] = "Seven";
        dict[8] = "Eight";
        dict[9] = "Nine";
        
        dict[10] = "Ten";
        dict[11] = "Eleven";
        dict[12] = "Twelve";
        dict[13] = "Thirteen";
        dict[14] = "Forteen";
        dict[15] = "Fifteen";
        dict[16] = "Sixteen";
        dict[17] = "Seventeen";
        dict[18] = "Eightteen";
        dict[19] = "Nineteen";
        dict[20] = "Twenty";
        
        dict[30] = "Thirty";
        dict[40] = "Forty";
        dict[50] = "Fifty";
        dict[60] = "Sixty";
        dict[70] = "Seventy";
        dict[80] = "Eighty";
        dict[90] = "Ninety";
        
        dict[100] = "Hundred";
        dict[1000] = "Thousand";
    }
 
};

std::string convertToWords(int number)
{
  
    Dictionary dic;
    
    std::string result;
    int place=0;
    int unitN = 0;
    while(number >0 )
    {
        // unit place
        auto r = number%10; 

        if(place == 0)
        {
            result += dic.dict[r];
            unitN = r;
        }
        else if(place == 1)
        {
            if(r == 1)
            {
                r = r*10 + unitN;
                result = dic.dict[r];
            }
            else
            {
                //swap
                auto temp = dic.dict[r*10] ;
                result = temp + " "+ result;
            }

        }
        else if(place == 2)
        {
            auto temp = dic.dict[100];
            result =  dic.dict[r] + " " + temp + " and " + result;
            
        }
        else if(place ==3)
        {
            auto temp = dic.dict[1000];
            result = dic.dict[r] + " "+ temp + " and " + result;
        }
        
        place++;
        number = number/10;
            
    }
    return result;
}

int main()
{
    std::cout<< " "<<convertToWords(1434)<<std::endl;
    std::cout<< " "<<convertToWords(0)<<std::endl;
    std::cout<< " "<<convertToWords(100)<<std::endl;
    std::cout<< " "<<convertToWords(999)<<std::endl;
    std::cout<< " "<<convertToWords(86)<<std::endl;

}
