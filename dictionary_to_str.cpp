#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>

std::vector<std::string> const& str_collection(std::set<std::string> words, std::string const& sentence,
std::vector<std::string>& result)
{
   std::vector<std::pair<int,int> > indexes;
   
   for (auto const& word:words)
    {
        auto const index = sentence.find(word);
        indexes.push_back(std::make_pair(index, word.size()));
              
    }
    
    std::sort(indexes.begin(), indexes.end());
    
    for (auto index : indexes)
    {
        result.push_back(sentence.substr(index.first, index.second)); 
    }

}

int main()
{
     std::set<std::string> s = {"quick", "brown", "the", "fox"};
     std::string sentence = "thequickbrownfox";
     std::vector<std::string> result;

    str_collection(s,sentence, result);
    auto lambda = [](std::string const& s){ std::cout<< " "<<s; };
    
    std::for_each(result.begin(),result.end(), lambda);
    return 0;
}
