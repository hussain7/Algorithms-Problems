// Example program
#include <iostream>
#include <string>
#include <map>
#include <utility>

bool isCombination(std::string const& str1, std::string const& str2
, std::string const& result)
{
    // first string
    std::map<char, int> set1;
    std::map<char, int> set2;
    
    int count=0;
    for(auto ch: str1)
    {
        set1.insert(std::make_pair(ch,count++));
    }
    
    count=0;
    for(auto ch: str2)
    {
        set2.insert(std::make_pair(ch,count++));;
    }
    
    // check if resukt is ok
    
    int strChar1Val = -1;
    int strChar2Val = -1;
    
    for(auto ch:result)
    {
        if(set1.find(ch) != set1.end())
        {
            if(set1[ch] < strChar1Val)
                return false;
            
            strChar1Val = set1[ch];
        }
        
        if(set2.find(ch) != set2.end())
        {
            if(set2[ch] < strChar2Val)
                return false;
            
            strChar2Val = set2[ch];
        }
    }

    return true;
}

int main()
{
  std::string str1= "abc", str2 = "def", str3 = "aebecf";
  std::cout << " answer " <<isCombination(str1,str2,str3);
}
