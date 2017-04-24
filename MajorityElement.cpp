#include <stdio.h>
#include <map>
#include <iostream>
#include <algorithm>

int usingMap(int *a, int n)
{
    std::map<int,int> bmap;
    for(int i=0;i<n;i++)
    {
        bmap[a[i]]++;
        
        if(bmap[a[i]] > n/2)
        {
            return a[i];
        }
    }
    
    return -1;
    
}
int complexityN(int *a, int n)
{
    int majority = a[0], count = 1;
    for(auto i=1; i<n; i++)
    {
        if( a[i] == majority)
        {
            count++;
        }
        else
        {
                count--;

        }
        if(count == 0)
        {
            
            majority = a[i]; 
            count++;
        }
    }
       
    if(count >= 1 )
    return majority; 
    else
    return -1;
}


int usingSort(int *a, int n)
{
    std::qsort(a, n, sizeof(int), [](const void*a, const void*b) { if( *(int*)a >= *(int*)b ) return 1; else return 0; } );   
    
    int majority = -1;
    int count=0;
    for(auto i=0; i<n; i++)
    {
        if(a[i] == majority)
        {
            count++;
            if(count >= n/2)
                return majority; 
        }
        else
        {
            count = 1;
            majority = a[i];
        }
    }
    return -1;
}
int main() {
	
	//code
	int a[9] = {3,3,4,5,6,3,3,2,3};
	std::cout<< "  "<< usingMap(a,9)<<std::endl;
	std::cout<< " n "<< complexityN(a,9)<<std::endl;
	std::cout << " sort " << usingSort(a,9);
	return 0;
}
