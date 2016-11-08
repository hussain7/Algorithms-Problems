// Algos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include<list>
#include <stack>
#include <vector>

using namespace std;

bool palindrome(std::list<int> const & list1)
{
    std::stack<int> tempStack;
    for(auto element:list1)
        tempStack.push(element);

    for(auto element:list1)
    {
        if(tempStack.top() != element)
        {
            return false;
        }
        tempStack.pop();
    }

    return true;
}

void testPlaindrome()
{
    int array[] = {0,2,3,3,2,0};
    std::list<int> list(array, array + sizeof(array)/sizeof(array[0]));
    auto check = palindrome(list);
    std::cout<< "list is palindrome "<< check << std::endl;

}

float median(const int* array, int size)
{
    float median = 0.0;
    if( size%2 == 1) // odd no of days
    {
        median = array[static_cast<int>(size/2)];
    }
    else
    {
        median = (array[static_cast<int>(size/2)] + array[static_cast<int>(size/2) + 1])/2;
    }
    return median;
}

void testmedian()
{
    int array[] = {0,2,3,3,2,0, 4,5,8,2};

    // sort array
    std::sort(array, array + sizeof(array)/ sizeof(array[0]));
    auto check = median(array, 4);
    std::cout<< "Median is: "<< check << std::endl;
}

int notificationofFrauds( std::vector<int> const& daysSpent, int days)
{
    int totalDays = daysSpent.size();
    // create a copy of vector
    std::vector<int> daysExpen(daysSpent);
    std::sort(daysExpen.begin(), daysExpen.end());

    size_t numberNotify = 0;
    //checking for notifications
    for(size_t i=days; i< daysSpent.size(); ++i)
    {
        auto medianVal = median(&daysExpen[i - days], days);
        std::cout << " median "<< medianVal<<" current value "<<daysSpent[i]<<std::endl;
        if(daysSpent[i] > medianVal)
        {
            // notify
            numberNotify++;
        }
    }
    return numberNotify;
}

void testnotification()
{
    int array[] = {0,2,3,3,2,0, 4,5,8,2};

//    std::sort(array, array + sizeof(array)/ sizeof(array[0]));
    std::vector<int> vec(array, array+ sizeof(array)/ sizeof(array[0]));
    int numberNotify = notificationofFrauds(vec, 4);
    std::cout<<" numberNotify "<< numberNotify<<std::endl;
}

int gcd(int m, int n)
{
    if(m%n == 0) return n;
    return(n, m%n);
}

int lcm(int m, int n, int gcd)
{
    return (m*n)/gcd;
}

int numberBetweenSet(std::vector<int> const& a, std::vector<int> const& b)
{
    int initial = a.begin();

    for(auto itr = a.begin()+1; itr != a.end(); ++itr)
    {
        auto gcdNo = gcd(initial,*itr);
        initial  = gcdNo;
    }
}

void gcdTest()
{
    cout<<"gcd "<< gcd(2,4) <<std::endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
    gcdTest();
    return 0;
}

