// merge sort
#include <stdio.h>
#include <iostream>
#include <memory>
#include <cstring>

using namespace std;

void merge(int a[], int s, int mid, int e);
void mergeSort(int a[], int s, int e)
{
    if(s < e)
    {
        auto mid = (s+e)/2;
        mergeSort(a, s, mid);
        mergeSort(a, mid+1, e);
        merge(a, s, mid, e);
    }
    
}

void merge(int a[], int s, int mid, int e)
{
    // create temp std::array
    auto n1 = mid+1 - s;
    auto n2 = e - mid;
    
    auto temp1 =  new int[n1];
    auto temp2 =  new int[n2];
    
    // copy into temp arrays
    //memcpy(temp1, a+s, n1);
    //memcpy(temp2, a+mid+1, n2);

    for(auto i=0;i<n1;i++)
    {
        temp1[i]=a[s+i];    
    }
    
    for(auto j=0; j<n2; j++)
    {
        temp2[j] = a[mid+1+j];
    }

    // merge temp arrays
    
    auto i=0,r=s,j=0;
    while(i< n1 && j <n2)
    {
        
        if(temp1[i] < temp2[j])
        {
            a[r] = temp1[i];
            i++;
        }
        else
        {
            a[r] = temp2[j];
            j++;
        }
        r++;
    }
    
    while(i<n1)
    {
        a[r] = temp1[i];
        i++;
        r++;
    }
    
    while(j<n2)
    {
        a[r] = temp2[j];
        j++;
        r++;
    }
    
    delete []temp1;
    delete []temp2;
}


int main() {
	//code
	int a[10] = {2,4,1,3,8,5,7,5,0,2};
	mergeSort(a,0,9);
	
	for(auto i=0;i<10;i++)
    {
      	std::cout<<a[i]<<" "; 
    }

	
	return 0;
}
