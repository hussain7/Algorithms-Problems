/*You are required to complete this function */

#include <string>
#include <cstring>

char *encode(char *src)
{     
  //Your code here 
  // aaaabbbccc
  std::string result;
  auto count=0,c=0;
  char previous = '\0' ;
  char displayChar = '\0';
  
  for(auto const& i=0; src[i] != '\0' ; i++)
  {
      if(src[i] == previous || i == 0)
        {
            displayChar = src[i];
            count++;
            
        }
    else if(src[i] != previous)
    {   
        result += displayChar;
        result += to_string(count);
        count=0;
    }
    previous = src[i];
    
  }

  result += displayChar;
  result += to_string(count);
  result += '\0';

  return const_cast<char *>(result.c_str());
}     
 
