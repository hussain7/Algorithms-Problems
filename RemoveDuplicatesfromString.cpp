// Example program
#include <iostream>
#include <string>
#include <map>
#include <set>

std::string removeDup(std::string const& input)
{
    std::string result;

    std::set<char> strSet;
    
    // for order
    std::map<int, char> orderMap;
    int count=0;
    for(auto const& ch :input)
    {
        if(strSet.find(ch) == strSet.end())
        {
            strSet.insert(ch);
            orderMap[count++] = ch;
        }
    }
        
        //iterate map
    for(auto itr = orderMap.begin(); itr != orderMap.end(); itr++)
    {
        result.push_back(itr->second);
    }
    
    return result;
}


int main()
{
    std::string name = "banana";
    std::cout<<"result "<<removeDup(name);    
}
