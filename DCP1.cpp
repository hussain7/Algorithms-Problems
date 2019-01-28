#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool check_sum_exists(std::vector<int>const& list, int sum)
{
    std::map<int, bool> exists_dic;
    
    for (const auto& x : list)
    {
        if( exists_dic.find(x) != exists_dic.end())
        {
            cout<<"Number is found ";
            return true;

        }
        else
        {
            exists_dic[sum - x] = true;
        }
    }
    
    return false;
}

int main()
{
 std::vector<int> list{1,22,45,32,78,17};
  int sum =54;
  bool result = check_sum_exists(list, sum);
  cout<<" result " <<result;
    return 0;
}
