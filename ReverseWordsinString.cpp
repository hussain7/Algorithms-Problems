// Example program
#include <iostream>
#include <string>
#include <sstream>

std::string reverse(std::string const& input)
{
  //tokenise
  std::istringstream str(input);
  std::string result = "";
  std::string word;
  do
  {
      result =  word +" " +result;
      //std::cout<< " "<<result<<std::endl;
  }while(std::getline(str,word,' '));
  
  return result;
}

int main()
{
    std::string in = "the long strong with dobara";
    std::cout << " "<<reverse(in);
}
